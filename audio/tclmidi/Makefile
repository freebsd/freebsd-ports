# Created by: Andreas Kohout <shanee@augusta.de>
# $FreeBSD$

PORTNAME=	tclmidi
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ringtail.its.monash.edu.au/pub/midi/PROGRAMS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language designed for creating and editing standard MIDI files

USES+=		tcl
NO_STAGE=	yes
MAKE_ENV=	TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" TCL_LIBDIR="${TCL_LIBDIR}"
MAKE_ENV+=	TCLSH=${TCLSH} FILESDIR="${FILESDIR}" MAN="${MAN1} ${MANN}"
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
MAKEFILE=	${FILESDIR}/BSDmakefile

MAN1=		mplay.1 mrec.1 tclmidi.1 minfo.1 midtotcl.1
MANN=		midiconf.n midievnt.n midifree.n midiget.n midigrep.n \
		midimake.n midimerg.n midiplay.n midiput.n midiread.n \
		midirec.n midirew.n midisplt.n midistop.n midiwait.n \
		midiwrit.n midivers.n midimove.n midicopy.n mididel.n \
		miditrck.n mididev.n miditime.n midifeat.n
MANCOMPRESSED=	maybe

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|iostream.h|iostream|g; s|iomanip.h|iomanip|g'

post-build:
	cd ${WRKSRC} && echo pkg_mkIndex . tclmidi31.so | ${TCLSH}

pre-su-install:
.for s in mplay mrec minfo midtotcl
	${SED} 's|/usr/local/bin/tclsh|${TCLSH}|' \
		< ${WRKSRC}/${s}.dist > ${PREFIX}/bin/${s}
	${CHMOD} 755 ${PREFIX}/bin/${s}
.endfor
	@${MKDIR} ${PREFIX}/lib/tclmidi
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${PREFIX}/lib/tclmidi
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>

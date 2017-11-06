# Created by: Andreas Kohout <shanee@augusta.de>
# $FreeBSD$

PORTNAME=	tclmidi
PORTVERSION=	3.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://ringtail.its.monash.edu.au/pub/midi/PROGRAMS/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Language designed for creating and editing standard MIDI files

BROKEN=		does not fetch, upstream gone
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-11-09

USES+=		tcl uidfix
MAKE_ENV=	TCL_INCLUDEDIR="${TCL_INCLUDEDIR}" TCL_LIBDIR="${TCL_LIBDIR}"
MAKE_ENV+=	TCLSH=${TCLSH} FILESDIR="${FILESDIR}" MAN="${MAN1} ${MANN}"
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
MAKEFILE=	${FILESDIR}/BSDmakefile

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
	    ${REINPLACE_CMD} -e 's|iostream.h|iostream|g; s|iomanip.h|iomanip|g'

post-build:
	cd ${WRKSRC} && echo pkg_mkIndex . tclmidi31.so | ${TCLSH}

pre-su-install:
.for s in mplay mrec minfo midtotcl
	${SED} 's|/usr/local/bin/tclsh|${TCLSH}|' \
		< ${WRKSRC}/${s}.dist > ${STAGEDIR}${PREFIX}/bin/${s}
	${CHMOD} 755 ${STAGEDIR}${PREFIX}/bin/${s}
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/tclmidi
	${INSTALL_DATA} ${WRKSRC}/pkgIndex.tcl ${STAGEDIR}${PREFIX}/lib/tclmidi

.include <bsd.port.mk>

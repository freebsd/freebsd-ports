# New ports collection makefile for:   linux-realplayer
# Date created:        31 January 1999
# Whom:                Kris Kennaway <kkennawa@physics.adelaide.edu.au>
#
# $FreeBSD$
#

PORTNAME=	linux-realplayer
PORTVERSION=	8.cs1
CATEGORIES=	audio graphics linux
MASTER_SITES=	# fetch manually
DISTNAME=	rp${PORTVERSION:R}_linux20_libc6_i386_${PORTVERSION:E}
EXTRACT_SUFX=	_rpm

MAINTAINER=	vns@delta.odessa.ua

RUN_DEPENDS=	/compat/linux/lib/libc.so.6:${PORTSDIR}/emulators/linux_base
BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio

EXTRACT_CMD=	rpm2cpio
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	| cpio -id --quiet
RADIR=		${PREFIX}/lib/RealPlayer${PORTVERSION:R}
WRKSRC=		${WRKDIR}/usr/lib/RealPlayer${PORTVERSION:R}
PLUGINSDIR=	${PREFIX}/lib/netscape-linux/plugins
RABINDIR=	${PREFIX}/bin

STRIP=		# Linux binary should not be stripped by INSTALL_PROGRAM as it uses /usr/bin/strip which then brands the binary as a FreeBSD ELF one.

.include <bsd.port.pre.mk>

.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX})
IGNORE=		may not be automatically fetched due to licensing\
		restrictions.  You MUST manually fetch the Linux RPM version after\
		reading and agreeing to the license at:\
		http://www.real.com/player/ \
		- once ${DISTFILES} has been downloaded, move it to\
		${DISTDIR} and then restart this build.
.endif

ONLY_FOR_ARCHS=	i386
NO_CDROM=	"Redistribution not allowed"
NO_BUILD=	yes

do-install:
	${MKDIR} ${RADIR}
.for f in mimeinstall.sh pluginstall.sh postinstall.sh
	${INSTALL_SCRIPT} ${WRKSRC}/${f} ${RADIR}
.endfor
.for f in realplay rpnp.so
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${RADIR}
.endfor
.for f in LICENSE Mailcap Mime.types README app.kdelnk audiosig.rm \
	firstrun.rm mime.kdelnk raclass.zip \
	realplay.desktop rp7.xpm rp7doc.png rp7doc.xpm rp7mini.xpm
	${INSTALL_DATA} ${WRKSRC}/${f} ${RADIR}
.endfor
.for d in Codecs Common Plugins
	${MKDIR} ${RADIR}/${d}
	${INSTALL_PROGRAM} ${WRKSRC}/${d}/*.so* ${RADIR}/${d}
.endfor
	${MKDIR} ${RADIR}/Plugins/ExtResources
	${INSTALL_PROGRAM} ${WRKSRC}/Plugins/ExtResources/* ${RADIR}/Plugins/ExtResources/

	${LN} -sf ${RADIR}/realplay ${RABINDIR}

.if exists(${PLUGINSDIR})
	${LN} -sf ${RADIR}/raclass.zip ${PLUGINSDIR}
	${LN} -sf ${RADIR}/rpnp.so ${PLUGINSDIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8
	${INSTALL_DATA} ${WRKSRC}/Help/readme ${PREFIX}/share/doc/RealPlayer8
	${INSTALL_DATA} ${WRKSRC}/Help/realplay.htm ${PREFIX}/share/doc/RealPlayer8
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8/realplay
	${INSTALL_DATA} ${WRKSRC}/Help/realplay/*.htm ${PREFIX}/share/doc/RealPlayer8/realplay
	${MKDIR} ${PREFIX}/share/doc/RealPlayer8/realplay/pics
	${INSTALL_DATA} ${WRKSRC}/Help/realplay/pics/* ${PREFIX}/share/doc/RealPlayer8/realplay/pics
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

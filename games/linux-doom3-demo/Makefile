# New ports collection makefile for:	doom3-demo
# Date created:			31 Mar 2005
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	doom3-demo
PORTVERSION=	1.1.1286
CATEGORIES=	games linux
MASTER_SITES=	http://www.hup.hu/~trey/DOOM3/ \
		http://darkstar.ist.utl.pt/pub/games/ \
		ftp://ftp.headoff.com/GameDemos/Doom3/
PKGNAMEPREFIX=	linux-
DISTNAME=	doom3-linux-${PORTVERSION}-demo.x86
EXTRACT_SUFX=	.run

MAINTAINER=	jylefort@FreeBSD.org
COMMENT=	DOOM III demo

RUN_DEPENDS=	${LINUXBASE}/usr/X11R6/lib/libX11.so.6:${PORTSDIR}/x11/linux-XFree86-libs

ONLY_FOR_ARCHS=	i386
PREFIX?=	${X11BASE}	# USE_X_PREFIX would pull in USE_XLIB
USE_LINUX=	yes
NO_PACKAGE=	Distfile is 462MB, set FORCE_PACKAGE if you really want to build this package
RESTRICTED=	Redistribution is limited, see license
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
DOOMDIR=	${PREFIX}/lib/${PORTNAME}
STRIP=		# do not brand Linux binaries as FreeBSD on INSTALL_PROGRAM

do-extract:
	@${MKDIR} ${WRKSRC}
	@cd ${WRKSRC} && ${TAIL} -c +8767 ${_DISTDIR}/${DISTFILES} | ${TAR} zxf -

post-patch:
	@${SED} -e 's|@DOOMDIR@|${DOOMDIR}|' ${FILESDIR}/doom3-demo.in \
		> ${WRKSRC}/doom3-demo

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/doom3-demo ${PREFIX}/bin

	${MKDIR} ${DOOMDIR}/demo
	${INSTALL_DATA} ${WRKSRC}/demo/demo00.pk4 ${DOOMDIR}/demo

	${INSTALL_PROGRAM} ${WRKSRC}/bin/Linux/x86/doom.x86 ${DOOMDIR}
.for f in gamex86.so libgcc_s.so.1 libstdc++.so.5
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOOMDIR}
	-${CHOWN} ${LIBOWN}:${LIBGRP} ${DOOMDIR}/${f}
	${CHMOD} ${LIBMODE} ${DOOMDIR}/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in License.txt README
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

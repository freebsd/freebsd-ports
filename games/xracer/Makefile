# New ports collection makefile for:	xracer
# Date created:				Nov 6th 1999
# Whom:					troll
#
# $FreeBSD$
#

PORTNAME=		xracer
PORTVERSION=		0.94
CATEGORIES=		games
MASTER_SITES=		http://xracer.annexia.org/
DISTFILES=		xracer-0.94.tar.gz xracer-data.tar.gz

MAINTAINER=		troll@digitalspark.net

LIB_DEPENDS=		jpeg.9:${PORTSDIR}/graphics/jpeg \
			GL.14:${PORTSDIR}/graphics/Mesa3

USE_XLIB=		yes
MAKEFILE=		Makefile
WRKSRC=			${WRKDIR}/xracer-0.94

USE_GMAKE=		YES
HAS_CONFIGURE=		YES

post-install:
	@ ${ECHO} "===>   Installing Tracks and Sound"
	@ ${CP} -R ${WRKSRC}/../xracer-data \
	   ${PREFIX}/lib/xracer
	@ ${CHMOD} -R 744 ${PREFIX}/lib/xracer
	@ ${CHMOD} -R a+X ${PREFIX}/lib/xracer
	@ ${ECHO} "===>   Installing Documentation"
	@ ${MKDIR} ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/README \
	   ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/AUTHORS \
	   ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/COPYING \
	   ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/NEWS \
	   ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/README.html \
	   ${PREFIX}/share/doc/xracer
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog \
	   ${PREFIX}/share/doc/xracer
	@ ${ECHO} "===>   Stripping Binaries"
	@ strip ${PREFIX}/bin/xracer
	@ strip ${PREFIX}/bin/mktrackmodel
	@ strip ${PREFIX}/bin/mktrack
	@ strip ${PREFIX}/bin/perlin
	@ strip ${PREFIX}/bin/test-poly-opts

	@${CAT} ${PKGDIR}/MESSAGE

.include <bsd.port.mk>

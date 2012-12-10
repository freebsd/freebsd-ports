# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	super_methane_brothers
PORTVERSION=	1.4.8
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	SF/methane/Methane%20Stable/Methane%20V${PORTVERSION}
DISTNAME=	methane-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the Amiga platform game of the same name

LIB_DEPENDS=	clanCore:${PORTSDIR}/devel/clanlib1 \
		mikmod:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
MAKEFILE=	makefile
BUILD_WRKSRC=	${WRKSRC}/source/linux

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; s|gcc|${CXX}|; \
		 s|^\(METHANE_FLAGS =\)|\1 ${CPPFLAGS}|; \
		 s|^\(METHANE_LIBS =\)|\1 ${LDFLAGS}|; \
		 s|0.8|1.0|g' \
		${BUILD_WRKSRC}/makefile

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/methane ${PREFIX}/bin
	${CHGRP} games ${PREFIX}/bin/methane
	${CHMOD} g+s ${PREFIX}/bin/methane
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/html
	cd ${WRKSRC} && ${INSTALL_DATA} authors history readme todo ${DOCSDIR}
	cd ${WRKSRC}/docs && ${INSTALL_DATA} *.gif *.html ${DOCSDIR}/html
.endif

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

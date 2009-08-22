# New ports collection makefile for:	Super Methane Brothers
# Date created:			22 Jan 2004
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $Carpetsmoker: ports/games/super_methane_brothers/Makefile,v 1.2 2007/08/02 13:45:02 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	super_methane_brothers
PORTVERSION=	1.4.8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/methane/Methane%20Stable/Methane%20V${PORTVERSION}
DISTNAME=	methane-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A port of the Amiga platform game of the same name

LIB_DEPENDS=	clanCore-0.8:${PORTSDIR}/devel/clanlib \
		mikmod:${PORTSDIR}/audio/libmikmod

USE_GMAKE=	yes
MAKEFILE=	makefile
BUILD_WRKSRC=	${WRKSRC}/source/linux

CPPFLAGS=	-I${LOCALBASE}/include -I${LOCALBASE}/include/ClanLib-0.8
LDFLAGS=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/ClanLib-0.8

post-patch:
	@${REINPLACE_CMD} -e \
		's|g++|${CXX}|; s|gcc|${CXX}|; \
		 s|^\(METHANE_FLAGS =\)|\1 ${CPPFLAGS}|; \
		 s|^\(METHANE_LIBS =\)|\1 ${LDFLAGS}|' \
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

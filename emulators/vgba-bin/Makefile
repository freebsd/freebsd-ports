# New ports collection makefile for:   vgb-bin
# Date created:		04 Aug 2000
# Whom:			Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	vgb
PORTVERSION=	2.1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.komkon.org/fms/VGB/
PKGNAMESUFFIX=	-bin
DISTNAME=	VGB${PORTVERSION:S/.//}-FreeBSD-80x86-bin
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	lioux@FreeBSD.org

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
NO_BUILD=	no
NO_WRKSUBDIR=	no

INSTALL_DIR=	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/vgb-debug ${PREFIX}/bin
	@${INSTALL_DIR} ${PREFIX}/share/vgb
	@${INSTALL_DATA} ${WRKSRC}/CART.GB ${PREFIX}/share/vgb
.if !defined(NOPORTDOCS)
	@${INSTALL_DIR} ${PREFIX}/share/doc/vgb
	@${INSTALL_DATA} ${WRKSRC}/VGB.html ${PREFIX}/share/doc/vgb
.endif # !defined(NOPORTDOCS)

.include <bsd.port.mk>

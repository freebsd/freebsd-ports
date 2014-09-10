# $FreeBSD$

PORTNAME=	grubik
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	games gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/Recreational/
DISTNAME=	GRubik

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual 3D Rubiks cube for GNUstep

LICENSE=	GPLv2

USES=		tar:tgz tar:tgz
USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

MAKE_ENV+=	GNUSTEP_INSTALLATION_DOMAIN=SYSTEM

post-patch:
	${RM} -rf ${WRKSRC}/GRubik.app/ix86
	${REINPLACE_CMD} -e 's|^//|# //|' \
		-e "/GNUSTEP_INSTALLATION_DIR/d" ${WRKSRC}/GNUmakefile

.include <bsd.port.mk>

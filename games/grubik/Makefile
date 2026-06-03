PORTNAME=	grubik
PORTVERSION=	0.1
PORTREVISION=	12
CATEGORIES=	games gnustep
MASTER_SITES=	http://debian.uni-essen.de/misc/GNUstep/Apps/Recreational/
DISTNAME=	GRubik

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Virtual 3D Rubiks cube for GNUstep

LICENSE=	GPLv2+

USES=		tar:tgz gnustep
USE_GNUSTEP=	back build

post-patch:
	${RM} -r ${WRKSRC}/GRubik.app/ix86

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/GRubik.app/GRubik

.include <bsd.port.mk>

PORTNAME=	Commons
PORTVERSION=	1.0.0
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel science
PKGNAMEPREFIX=	ISCD-

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Common code shared by many ISCD softwares
WWW=		https://github.com/ISCDtoolbox/Commons

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake

USE_GITHUB=	yes
GH_ACCOUNT=	ISCDtoolbox
USE_LDCONFIG=	yes

CFLAGS+=	-funroll-loops

.include <bsd.port.mk>

PORTNAME=	unshield
PORTVERSION=	1.6.2
CATEGORIES=	archivers

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extract data from InstallShield CAB files
WWW=		https://github.com/twogood/unshield

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake cpe ssl

CFLAGS+=	-fPIC
USE_LDCONFIG=	yes

PLIST_SUB=	PORTVERSION=${PORTVERSION}

CPE_VENDOR=	unshield_project

GH_ACCOUNT=	twogood
USE_GITHUB=	yes

.include <bsd.port.mk>

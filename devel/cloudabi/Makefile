PORTNAME=	cloudabi
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19
CATEGORIES=	devel

MAINTAINER=	ed@FreeBSD.org
COMMENT=	Constants, types and data structures used by CloudABI
WWW=		https://github.com/NuxiNL/cloudabi

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Unmaintained upstream since 2020
EXPIRATION_DATE=2024-11-30

USE_GITHUB=	yes
GH_ACCOUNT=	NuxiNL

NO_BUILD=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/headers/* ${STAGEDIR}${PREFIX}/include/

.include <bsd.port.mk>

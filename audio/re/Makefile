PORTNAME=	re
DISTVERSIONPREFIX=	v
DISTVERSION=	3.4.0
CATEGORIES=	audio devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for real-time comms with async IO support
WWW=		https://github.com/baresip

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	baresip
USE_LDCONFIG=	yes

# FIXME values of the next 3 variables taken from source code Makefile
ABI_MAJOR=	14
ABI_AGE=	12
ABI_REV=	0
PLIST_SUB=	ABI_MAJOR=${ABI_MAJOR}
PLIST_SUB+=	ABI_AGE=${ABI_AGE} \
		ABI_REV=${ABI_REV}

.include <bsd.port.mk>

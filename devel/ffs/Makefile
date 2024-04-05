PORTNAME=	ffs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.0-132
DISTVERSIONSUFFIX=	-gcc3da1a
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Middleware library for data communication, representation, marshaling
WWW=		https://github.com/GTkorvo/ffs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libatl.so:devel/atl \
		libdill.so:devel/dill

USES=		bison cmake perl5 shebangfix
USE_PERL5=	build
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	GTkorvo

SHEBANG_FILES=	ffs-config.in

.include <bsd.port.mk>

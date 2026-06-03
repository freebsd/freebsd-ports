PORTNAME=	check
PORTVERSION=	0.15.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libcheck/check/releases/download/${PORTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Unit test framework for C
WWW=		https://libcheck.github.io/check/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LESSER

USES=		libtool pkgconfig

CONFIGURE_ENV=	ac_cv_path_AWK_PATH=${AWK}
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

INFO=		check

OPTIONS_DEFINE=	DOCS EXAMPLES

.include <bsd.port.mk>

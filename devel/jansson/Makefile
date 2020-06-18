# Created by: vanilla@
# $FreeBSD$

PORTNAME=	jansson
PORTVERSION=	2.13.1
CATEGORIES=	devel
MASTER_SITES=	http://www.digip.org/jansson/releases/

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	C library for encoding, decoding, and manipulating JSON data

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash>=0:shells/bash

USES=		cpe pathfix pkgconfig tar:bzip2 libtool shebangfix
SHEBANG_FILES=	scripts/clang-format scripts/clang-format-check
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

CPE_VENDOR=	jansson_project

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>

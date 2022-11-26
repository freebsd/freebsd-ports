PORTNAME=	colm
DISTVERSION=	0.14.7-43
DISTVERSIONSUFFIX=	-gd00ef793
CATEGORIES=	lang

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Colm Programming Language
WWW=		https://github.com/adrian-thurston/colm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	bash:shells/bash
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	adrian-thurston

SHEBANG_GLOB=	*.sh
SHEBANG_FILES=	test/runtests

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip
TEST_TARGET=	check # 1 tests fails, see https://github.com/adrian-thurston/colm/issues/153

PORTSCOUT=	limit:^[0-9]+\.[0-9]+ # ignore alpha-numeric tags like colm-barracuda-v5

.include <bsd.port.mk>

PORTNAME=	pycdc
DISTVERSION=	g20250704
CATEGORIES=	devel

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Python bytecode disassembler and decompiler
WWW=		https://github.com/zrax/pycdc

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang python:env,test shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	zrax
GH_TAGNAME=	a267bfb

SHEBANG_FILES=	scripts/pymultic scripts/token_dump tests/run_tests.py

TEST_TARGET=	check

PLIST_FILES=	bin/pycdas \
		bin/pycdc

.include <bsd.port.mk>

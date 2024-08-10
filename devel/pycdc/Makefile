PORTNAME=	pycdc
DISTVERSION=	g20240806
CATEGORIES=	devel

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Python bytecode disassembler and decompiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bash:shells/bash

USES=		cmake compiler:c++11-lang python:env,test shebangfix
SHEBANG_FILES=	scripts/pymultic scripts/token_dump tests/*.sh

USE_GITHUB=	yes
GH_ACCOUNT=	zrax
GH_TAGNAME=	48d1bfa

TEST_TARGET=	check

PLIST_FILES=	bin/pycdas \
		bin/pycdc

post-patch:
	@${REINPLACE_CMD} -e 's|%%PYTHON_CMD%%|${PYTHON_CMD}|g' \
	    ${PATCH_WRKSRC}/tests/decompyle_test.sh

.include <bsd.port.mk>

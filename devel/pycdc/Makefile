PORTNAME=	pycdc
DISTVERSION=	g20240806
CATEGORIES=	devel

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	Python bytecode disassembler and decompiler

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		cmake shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	zrax
GH_TAGNAME=	48d1bfa

SHEBANG_FILES=	tests/all_tests.sh \
		tests/decompyle_test.sh

PLIST_FILES=	bin/pycdas \
		bin/pycdc

do-test:
	cd ${BUILD_WRKSRC} && ninja check

.include <bsd.port.mk>

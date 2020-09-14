# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	bear
DISTVERSION=	2.4.4
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Tool that generates a compilation database for clang tooling

LICENSE=	GPLv3

USES=		cmake python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear
USE_LDCONFIG=	yes

SHEBANG_FILES=	bear/bear.py
python_OLD_CMD=	"/usr/bin/env @BEAR_PYTHON_EXECUTABLE@"

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/install(FILES COPYING/d' \
		-e '/{CMAKE_INSTALL_DOCDIR}/d' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

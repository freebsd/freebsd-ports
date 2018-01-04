# Created by: Jov <amutu@amutu.com>
# $FreeBSD$

PORTNAME=	bear
PORTVERSION=	2.3.6
CATEGORIES=	devel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	amutu@amutu.com
COMMENT=	Tool that generates a compilation database for clang tooling

LICENSE=	GPLv3

USE_GITHUB=	yes
GH_ACCOUNT=	rizsotto
GH_PROJECT=	Bear

USES=		cmake shebangfix python
USE_LDCONFIG=	yes

SHEBANG_FILES=	bear/main.py.in

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e '/install(FILES COPYING/d' \
		-e '/{CMAKE_INSTALL_DOCDIR}/d' \
		${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

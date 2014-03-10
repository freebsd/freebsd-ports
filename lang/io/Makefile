# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	io
PORTVERSION=	2011.09.12
PORTREVISION=	3
CATEGORIES=	lang

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Small prototype-based programming language

LICENSE=	BSD

OPTIONS_DEFINE=	DOCS EXAMPLES
OPTIONS_GROUP=	ADDONS

USE_GCC=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	stevedekorte
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	23afbcc
MAKE_JOBS_UNSAFE=yes

USE_LDCONFIG=	yes
USES=		cmake:outsource

PORTDOCS=	*
PORTEXAMPLES=	*

.include "${.CURDIR}/Makefile.addons"

post-patch:
	${REINPLACE_CMD} -e 's/^[ ]*add_subdirectory/#&/' \
		${WRKSRC}/addons/CMakeLists.txt
.for addon in ${ADDONS}
	${ECHO} "add_subdirectory(${addon})" >> ${WRKSRC}/addons/CMakeLists.txt
.endfor
	${FIND} ${WRKSRC}/addons -name "*.bak" -o -name "*.orig" -delete

post-install:
	${MKDIR}  ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} .  ${STAGEDIR}${DOCSDIR}
	${MKDIR}  ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/samples && ${COPYTREE_SHARE} .  ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>

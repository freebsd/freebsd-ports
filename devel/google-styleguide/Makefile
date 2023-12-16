PORTNAME=	styleguide
PORTVERSION=	20231121
CATEGORIES=	devel
PKGNAMEPREFIX=	google-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to assist with Google style guide compliance
WWW=		https://google.github.io/styleguide/ \
		https://github.com/google/styleguide

# cpplint.py and cpplint_unittest.py are released under BSD3CLAUSE
# style guides is released under CC-BY-3.0
# google-c-style.el is released under GPLv1+
LICENSE=	BSD3CLAUSE CC-BY-3.0 GPLv1+
LICENSE_COMB=	multi

USES=		python shebangfix

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	4d9a478

SHEBANG_FILES=	cpplint/cpplint.py cpplint/cpplint_unittest.py

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cpplint/cpplint.py ${WRKSRC}/cpplint/cpplint_unittest.py ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${WRKSRC}/google-c-style.el ${WRKSRC}/google_python_style.vim ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/cpplint ${STAGEDIR}${DOCSDIR}/docguide
	${INSTALL_DATA} ${WRKSRC}/*.css ${WRKSRC}/*.html ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/cpplint/README ${STAGEDIR}${DOCSDIR}/cpplint
	(cd ${WRKSRC}/docguide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/docguide)

.include <bsd.port.mk>

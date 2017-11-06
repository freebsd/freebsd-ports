# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	styleguide
PORTVERSION=	20170630
CATEGORIES=	devel
PKGNAMEPREFIX=	google-

MAINTAINER=	amutu@amutu.com
COMMENT=	Tool to assist with Google style guide compliance

# cpplint.py and cpplint_unittest.py under BSD3CLAUSE
# style guides under CC-BY-3.0
# google-c-style.el under GPLv1+
LICENSE=	BSD3CLAUSE CC-BY-3.0 GPLv1+
LICENSE_COMB=	multi

USES=		python shebangfix

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	d75bd35

NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	cpplint/cpplint.py cpplint/cpplint_unittest.py

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/cpplint/cpplint.py ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/cpplint/cpplint_unittest.py ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/google_python_style.vim  ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/google-c-style.el  ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}/cpplint
	${INSTALL_DATA} ${WRKSRC}/cpplint/README ${STAGEDIR}${DOCSDIR}/cpplint
	${MKDIR} ${STAGEDIR}${DOCSDIR}/docguide
	(cd ${WRKSRC}/docguide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/docguide)

.include <bsd.port.mk>

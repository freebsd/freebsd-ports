# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	git-bzr-ng
PORTVERSION=	git20140423
CATEGORIES=	devel

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Bi-directional git to bzr bridge

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	git:${PORTSDIR}/devel/git \
		bzr:${PORTSDIR}/devel/bzr \
		${PYTHON_SITELIBDIR}/bzrlib/plugins/fastimport/__init__.py:${PORTSDIR}/devel/bzr-fastimport

USE_GITHUB=	yes
GH_ACCOUNT=	termie
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	9878a30

NO_BUILD=	yes
PLIST_FILES=	libexec/git-core/git-bzr
PLIST_DIRSTRY=	libexec/git-core
PORTDOCS=	*
USE_PYTHON_RUN=	2

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/git-core
	${INSTALL_SCRIPT} ${WRKSRC}/git-bzr ${STAGEDIR}${PREFIX}/libexec/git-core/
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.rst ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

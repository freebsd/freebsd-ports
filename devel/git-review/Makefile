PORTNAME=	git-review
DISTVERSION=	1.28.0
PORTREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP

PATCH_SITES=	https://opendev.org/opendev/${PORTNAME}/commit/
PATCHFILES+=	7182166ec00ad3645821435d72c5424b4629165f.diff:-p1 # Fix run with git >= 2.34.0

MAINTAINER=	dereckson@gmail.com
COMMENT=	Allow to push code to review and interact with a Gerrit server

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pbr>0:devel/py-pbr@${PY_FLAVOR}
RUN_DEPENDS=	git:devel/git \
		${PYTHON_PKGNAMEPREFIX}requests>2.4:www/py-requests@${PY_FLAVOR}

USES=		python:3.6+
USE_PYTHON=	autoplist distutils concurrent optsuffix
NO_ARCH=	yes

PORTDOCS=	README.rst HACKING.rst AUTHORS

OPTIONS_DEFINE=	DOCS

post-install:
	${INSTALL_MAN} ${WRKSRC}/git-review.1 ${STAGEDIR}${MANPREFIX}/man/man1

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PORTNAME=	styleguide
PORTVERSION=	20250709
CATEGORIES=	devel
PKGNAMEPREFIX=	google-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Tool to assist with Google style guide compliance
WWW=		https://google.github.io/styleguide/ \
		https://github.com/google/styleguide

# style guides is released under CC-BY-3.0
# google-c-style.el is released under GPLv1+
LICENSE=	CC-BY-3.0 GPLv1+
LICENSE_COMB=	multi

USES=		python

NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	google
GH_TAGNAME=	124b0b8

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xml ${WRKSRC}/google-c-style.el ${WRKSRC}/google_python_style.vim ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/docguide
	${INSTALL_DATA} ${WRKSRC}/*.css ${WRKSRC}/*.html ${WRKSRC}/*.md ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docguide && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/docguide

.include <bsd.port.mk>

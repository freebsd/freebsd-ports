PORTNAME=	git-cinnabar
DISTVERSION=	0.7.3
CATEGORIES=	devel

MAINTAINER=	jbeich@FreeBSD.org
COMMENT=	Git remote helper to interact with Mercurial repositories
WWW=		https://github.com/glandium/git-cinnabar

LICENSE=	GPLv2 MPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	libzstd.so:archivers/zstd \
		libcurl.so:ftp/curl
RUN_DEPENDS=	git:devel/git

USES=		cargo gmake
USE_GITHUB=	yes
GH_ACCOUNT=	glandium
GH_TUPLE=	git-for-windows:git:v2.50.1.windows.1:git/git-core
DATADIR=	${PREFIX}/libexec/git-core
PORTDATA=	*
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MV} ${STAGEDIR}${PREFIX}/bin/${PORTNAME} ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/${PORTNAME} \
		${STAGEDIR}${DATADIR}/git-remote-hg
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

PORTNAME=	lookup
DISTVERSION=	1.99.96.20200725
CATEGORIES=	japanese elisp

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Emacs search interface for CD-ROM books, etc
WWW=		https://lookup2.github.io/

LICENSE=	GPLv2+

RUN_DEPENDS=	ja-eblook>0:japanese/eblook

USES=		autoreconf emacs:build makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	lookup2
GH_PROJECT=	lookup2
GH_TAGNAME=	06f827d92d59cf679e7340247d9eeaa23ec0ffe5
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}

NO_ARCH=	yes

INFO=		lookup
PORTDOCS=	AUTHORS ChangeLog NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

PORTNAME=	lookup
PORTVERSION=	1.99.96.20180209
PORTREVISION=	22
CATEGORIES=	japanese elisp

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Emacs search interface for CD-ROM books, etc
WWW=		https://lookup2.github.io/

LICENSE=	GPLv2+

USES=		autoreconf emacs:build makeinfo
USE_GITHUB=	yes
GH_ACCOUNT=	lookup2
GH_PROJECT=	lookup2
GH_TAGNAME=	c4f4986
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_SITE_LISPDIR}

CONFLICTS_INSTALL=	ja-lookup-emacs_*

NO_ARCH=	yes

INFO=		lookup
PORTDOCS=	AUTHORS ChangeLog NEWS README.md

OPTIONS_DEFINE=	DOCS

post-install:
	@${FIND} ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}/lookup \
		-name "*.elc" -delete
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

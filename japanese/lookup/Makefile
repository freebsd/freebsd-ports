# Created by: Satoshi Taoka <taoka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lookup
PORTVERSION=	1.99.96.20180209
PORTREVISION=	5
CATEGORIES=	japanese elisp
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Emacs search interface for CD-ROM books, etc

LICENSE=	GPLv2+

USES=		autoreconf emacs makeinfo

USE_GITHUB=	yes
GH_ACCOUNT=	lookup2
GH_PROJECT=	lookup2
GH_TAGNAME=	c4f4986

INFO=		lookup
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-emacs=${EMACS_CMD} \
		--with-lispdir=${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS ChangeLog NEWS README.md

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

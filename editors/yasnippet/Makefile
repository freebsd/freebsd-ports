# $FreeBSD$

PORTNAME=	yasnippet
PORTVERSION=	0.6.1c
PORTREVISION=	10
CATEGORIES=	editors
MASTER_SITES=	GOOGLE_CODE
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		yasnippet-doc-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	YASnippet is a template system for Emacs

BROKEN=		Unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2015-11-26
USES=		tar:bzip2
USE_EMACS=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

post-patch:
	@${FIND} ${WRKSRC}/snippets -type d -empty | ${XARGS} ${RMDIR}

do-install:
	${INSTALL_DATA} ${WRKSRC}/dropdown-list.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	${INSTALL_DATA} ${WRKSRC}/yasnippet.el ${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} snippets ${STAGEDIR}${DATADIR}
	cd ${WRKDIR}/doc && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

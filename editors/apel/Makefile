PORTNAME=	apel
PORTVERSION=	10.8.${SNAPDATE}
PORTREVISION=	2
CATEGORIES=	editors elisp

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Portable Emacs Library
WWW=		https://github.com/wanderlust/apel

LICENSE=	GPLv2

USES=		emacs:build
USE_GITHUB=	yes
GH_ACCOUNT=	wanderlust
GH_TAGNAME=	2383abf

SNAPDATE=	20250531

CONFLICTS_INSTALL=	apel-emacs_*

NO_ARCH=	yes
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in README.* ; do \
	    ${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR} ; \
	done)

.include <bsd.port.mk>

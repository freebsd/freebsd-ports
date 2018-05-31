# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apel
PORTVERSION=	${APEL_VER}
PORTREVISION=	16
CATEGORIES=	editors elisp
MASTER_SITES=	http://git.chise.org/elisp/dist/apel/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Portable Emacs Library

LICENSE=	GPLv2

USES=		emacs

NO_ARCH=	yes

APEL_VER=	10.8
ALL_TARGET=	elc
MAKE_ARGS+=	PREFIX="${STAGEDIR}${PREFIX}" \
		LISPDIR="${STAGEDIR}${PREFIX}/${EMACS_SITE_LISPDIR}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
	    ${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR} ; \
	done)

.include <bsd.port.mk>

# Created by: Shigeyuki FUKUSHIMA <shige@FreeBSD.org>
# $FreeBSD$

PORTNAME=	apel
PORTVERSION=	${APEL_VER}
PORTREVISION=	12
CATEGORIES=	editors elisp
MASTER_SITES=	http://git.chise.org/elisp/dist/apel/
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Portable Emacs Library

LICENSE=	GPLv2

# distfile version
APEL_VER=	10.8
# apel lispdir
APEL_LISPDIR?=			${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}
APEL_VERSION_SPECIFIC_LISPDIR?=	${LOCALBASE}/${EMACS_VERSION_SITE_LISPDIR}

# emacs port setup
USE_EMACS=	yes

DESCR=		${PKGDIR}/pkg-descr

# target name for make build
ALL_TARGET?=	elc
# environments
MAKE_ARGS+=	PREFIX="${STAGEDIR}${LOCALBASE}" \
		LISPDIR="${STAGEDIR}${APEL_LISPDIR}" \
		VERSION_SPECIFIC_LISPDIR="${STAGEDIR}${APEL_VERSION_SPECIFIC_LISPDIR}"

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@(cd ${WRKSRC} ; \
	for i in ChangeLog README.* ; do \
	    ${INSTALL_DATA} $${i} ${STAGEDIR}${DOCSDIR} ; \
	done)

.include <bsd.port.mk>

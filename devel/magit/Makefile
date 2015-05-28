# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magit
PORTVERSION=	1.4.0
PORTREVISION=	1
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GFDL GPLv3
LICENSE_COMB=	multi

BUILD_DEPENDS=	git-modes-${EMACS_PORT_NAME}>0:${PORTSDIR}/devel/git-modes
RUN_DEPENDS=	git-modes-${EMACS_PORT_NAME}>0:${PORTSDIR}/devel/git-modes

USE_GITHUB=	yes

USES=		gmake makeinfo
USE_EMACS=	YES
INFO=		magit
PORTDOCS=	AUTHORS.md

OPTIONS_DEFINE=			DOCS

.include <bsd.port.pre.mk>

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
MAKE_ENV+=	EFLAGS="-L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/git-modes" \
		lispdir=${PREFIX}/${ELISPDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		docdir=${DOCSDIR}
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

.include <bsd.port.post.mk>

# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magit
PORTVERSION=	1.2.0
PORTREVISION=	2
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://cloud.github.com/downloads/magit/magit/
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GFDL GPLv3
LICENSE_COMB=	multi

RUN_DEPENDS=	git>0:${PORTSDIR}/devel/git

USES=		gmake
USE_EMACS=	YES
INFO=		magit

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

MAKE_ENV+=	ELISPDIR=${STAGEDIR}${PREFIX}/${ELISPDIR} \
		INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH}
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

.include <bsd.port.mk>

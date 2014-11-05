# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magit
PORTVERSION=	1.2.0
PORTREVISION=	3
CATEGORIES=	devel elisp
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://cloud.github.com/downloads/magit/magit/
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GFDL GPLv3
LICENSE_COMB=	multi

USES=		gmake
USE_EMACS=	YES
INFO=		magit

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

MAKE_ENV+=	ELISPDIR=${STAGEDIR}${PREFIX}/${ELISPDIR} \
		INFODIR=${STAGEDIR}${PREFIX}/${INFO_PATH}
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

OPTIONS_DEFINE=		GIT_SUBVERSION
GIT_SUBVERSION_DESC=	Use devel/git-subversion as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:${PORTSDIR}/devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git>0:${PORTSDIR}/devel/git

.include <bsd.port.mk>

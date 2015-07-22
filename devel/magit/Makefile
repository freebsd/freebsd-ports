# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magit
PORTVERSION=	2.1.0
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GPLv3

BUILD_DEPENDS=	git:${PORTSDIR}/devel/git \
		dash.el>0:${PORTSDIR}/devel/dash.el
RUN_DEPENDS=	dash.el>0:${PORTSDIR}/devel/dash.el

USE_GITHUB=	yes

USES=		gmake makeinfo
USE_EMACS=	YES
INFO=		magit magit-popup with-editor
PORTDOCS=	AUTHORS.md
NO_ARCH=	YES

OPTIONS_DEFINE=			DOCS GIT_SUBVERSION
GIT_SUBVERSION_DESC=		Use devel/git-subversion as backend
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:${PORTSDIR}/devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git>0:${PORTSDIR}/devel/git

.include <bsd.port.pre.mk>

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
MAKE_ENV+=	LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_SITE_LISPDIR}" \
		VERSION=${PORTVERSION} \
		lispdir=${PREFIX}/${ELISPDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		docdir=${DOCSDIR}
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

.include <bsd.port.post.mk>

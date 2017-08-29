# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>
# $FreeBSD$

PORTNAME=	magit
PORTVERSION=	2.10.3
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-${EMACS_PORT_NAME}

MAINTAINER=	yasu@utahime.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GPLv3

BUILD_DEPENDS=	dash.el>=2.12.1:devel/dash.el \
		with-editor-${EMACS_PORT_NAME}>=2.5.0:editors/with-editor
RUN_DEPENDS=	dash.el>=2.12.1:devel/dash.el \
		with-editor-${EMACS_PORT_NAME}>=2.5.0:editors/with-editor

USES=		gmake makeinfo
USE_EMACS=	yes
USE_GITHUB=	yes
INFO=		magit magit-popup
PORTDOCS=	AUTHORS.md
NO_ARCH=	yes

OPTIONS_DEFINE=			DOCS GIT_SUBVERSION
GIT_SUBVERSION_DESC=		Use devel/git-subversion as backend
GIT_SUBVERSION_BUILD_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_BUILD_DEPENDS_OFF=	git>0:devel/git
GIT_SUBVERSION_RUN_DEPENDS=	git-subversion>0:devel/git-subversion
GIT_SUBVERSION_RUN_DEPENDS_OFF=	git>0:devel/git

.include <bsd.port.pre.mk>

ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}
MAKE_ENV+=	INSTALL_INFO=install-info \
		LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_SITE_LISPDIR}  -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}" \
		VERSION=${PORTVERSION} \
		lispdir=${PREFIX}/${ELISPDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		docdir=${DOCSDIR}
PLIST_SUB+=	ELISPDIR=${ELISPDIR}

.include <bsd.port.post.mk>

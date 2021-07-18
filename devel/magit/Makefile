# Created by: Jun Kuriyama <kuriyama@FreeBSD.org>

PORTNAME=	magit
PORTVERSION=	3.1.1
CATEGORIES=	devel elisp
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/
PKGNAMESUFFIX=	${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@utahime.org
COMMENT=	Interface to Git for Emacs

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>=2.14.1:devel/dash.el@${EMACS_FLAVOR} \
		ghub${EMACS_PKGNAMESUFFIX}>=3.0.0:devel/ghub@${EMACS_FLAVOR} \
		transient${EMACS_PKGNAMESUFFIX}>=0:devel/transient@${EMACS_FLAVOR} \
		with-editor${EMACS_PKGNAMESUFFIX}>=2.8.0:editors/with-editor@${EMACS_FLAVOR}
RUN_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>=2.14.1:devel/dash.el@${EMACS_FLAVOR} \
		ghub${EMACS_PKGNAMESUFFIX}>=3.0.0:devel/ghub@${EMACS_FLAVOR} \
		transient${EMACS_PKGNAMESUFFIX}>=0:devel/transient@${EMACS_FLAVOR} \
		with-editor${EMACS_PKGNAMESUFFIX}>=2.8.0:editors/with-editor@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo

MAKE_ENV+=	docdir=${DOCSDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		INSTALL_INFO=install-info \
		lispdir=${PREFIX}/${_ELISPDIR} \
		LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/ghub" \
		VERSION=${PORTVERSION}

CONFLICTS_INSTALL=	magit-devel-emacs*

NO_ARCH=	yes

INFO=		magit magit-section
PLIST_SUB+=	ELISPDIR=${_ELISPDIR}
PORTDOCS=	AUTHORS.md

OPTIONS_DEFINE=			DOCS LIBEGIT2
OPTIONS_SUB=			yes
LIBEGIT2_DESC=			Use libegit2 as backend (EXPERIMENTAL)
LIBEGIT2_BUILD_DEPENDS=		libegit2${EMACS_PKGNAMESUFFIX}>=g20200515:devel/libegit2@${EMACS_FLAVOR}
LIBEGIT2_BUILD_DEPENDS_OFF=	git:devel/git
LIBEGIT2_RUN_DEPENDS=		libegit2${EMACS_PKGNAMESUFFIX}>=g20200515:devel/libegit2@${EMACS_FLAVOR}
LIBEGIT2_RUN_DEPENDS_OFF=	git:devel/git
LIBEGIT2_VARS_OFF=		MAKE_ENV+=BUILD_MAGIT_LIBGIT=false

_ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

.include <bsd.port.mk>

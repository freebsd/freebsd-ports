PORTNAME=	magit
DISTVERSIONPREFIX=	v
DISTVERSION=	3.3.0-86
DISTVERSIONSUFFIX=	-ga5f6705b
CATEGORIES=	devel elisp
PKGNAMESUFFIX=	-devel${EMACS_PKGNAMESUFFIX}

MAINTAINER=	yasu@FreeBSD.org
COMMENT=	Interface to Git for Emacs (Development Version)

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		transient${EMACS_PKGNAMESUFFIX}>=0.3.7:devel/transient@${EMACS_FLAVOR} \
		with-editor${EMACS_PKGNAMESUFFIX}>=3.0.5:editors/with-editor@${EMACS_FLAVOR}
RUN_DEPENDS=	dash.el${EMACS_PKGNAMESUFFIX}>=2.19.1:devel/dash.el@${EMACS_FLAVOR} \
		transient${EMACS_PKGNAMESUFFIX}>=0.3.7:devel/transient@${EMACS_FLAVOR} \
		with-editor${EMACS_PKGNAMESUFFIX}>=3.0.5:editors/with-editor@${EMACS_FLAVOR}

USES=		emacs gmake makeinfo
USE_GITHUB=	yes

MAKE_ENV+=	docdir=${DOCSDIR} \
		infodir=${PREFIX}/${INFO_PATH} \
		INSTALL_INFO=install-info \
		lispdir=${PREFIX}/${_ELISPDIR} \
		LOAD_PATH="-L ${WRKSRC}/lisp -L ${PREFIX}/${EMACS_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR} -L ${PREFIX}/${EMACS_VERSION_SITE_LISPDIR}/ghub" \
		VERSION=${PORTVERSION}
# Parallel build fails if Emacs is built with native compilation enabled
MAKE_JOBS_UNSAFE=	yes

CONFLICTS_INSTALL=	magit-emacs*

NO_ARCH=	yes

INFO=		magit magit-section
PLIST_SUB+=	ELISPDIR=${_ELISPDIR}
PORTDOCS=	AUTHORS.md ReleaseNote

OPTIONS_DEFINE=			DOCS LIBEGIT2
OPTIONS_SUB=			yes
LIBEGIT2_DESC=			Use libegit2 as backend (EXPERIMENTAL)
LIBEGIT2_BUILD_DEPENDS=		libegit2${EMACS_PKGNAMESUFFIX}>=g20200515:devel/libegit2@${EMACS_FLAVOR}
LIBEGIT2_BUILD_DEPENDS_OFF=	git:devel/git
LIBEGIT2_RUN_DEPENDS=		libegit2${EMACS_PKGNAMESUFFIX}>=g20200515:devel/libegit2@${EMACS_FLAVOR}
LIBEGIT2_RUN_DEPENDS_OFF=	git:devel/git
LIBEGIT2_VARS_OFF=		MAKE_ENV+=BUILD_MAGIT_LIBGIT=false

_ELISPDIR=	${EMACS_VERSION_SITE_LISPDIR}/${PORTNAME}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/RelNotes/3.4.0.org \
		${STAGEDIR}${DOCSDIR}/ReleaseNote

.include <bsd.port.mk>

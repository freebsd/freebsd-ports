# New ports collection makefile for:	emacs20-dl-canna
# Version required:	1.2
# Date created:		10 October 1998
# Whom:			shige
#
# $FreeBSD$
#

DISTNAME=	emacs-canna-${DLCANNA_VER}
PKGNAME=	ja-emacs20-dl-canna-${DLCANNA_VER}
CATEGORIES=	japanese editors
MASTER_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/emacs-20-dl/ \
		${MASTER_SITE_PORTS_JP} 

MAINTAINER=	shige@FreeBSD.org

LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
# Building this port requires emacs-dl source tree: ${EMACSDL_DIR}:configure
BUILD_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		/nonexistent:${EMACSDL_DIR}:configure \
		${APEL_DEPENDS}:${PORTSDIR}/editors/apel-emacs20
RUN_DEPENDS=	emacs-dl-${EMACS_VER}:${EMACSDL_DIR} \
		${APEL_DEPENDS}:${PORTSDIR}/editors/apel-emacs20

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-canna-includes=${PREFIX}/include \
		--with-canna-libraries=${PREFIX}/lib \
		--with-emacs-srcdir=${EMACSDL_SRCDIR}
CONFIGURE_ENV=	EMACS="emacs-dl-${EMACS_VER}"
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${MACHINE_ARCH}--freebsd \
		DLCANNA_VER=${DLCANNA_VER} LISPDIR=${LISPDIR} DOCDIR=${DOCDIR}

# ports variables
EMACS_VER=	20.4
EMACSDL_DIR=	${.CURDIR}/../../editors/emacs20-dl
EMACSDL_SRCDIR=	${WRKDIRPREFIX}${EMACSDL_DIR}/work/emacs-${EMACS_VER}/src
APEL_DEPENDS=	${PREFIX}/share/emacs/${EMACS_VER}/site-lisp/emu/emu.el
LISPDIR=	share/emacs/site-lisp
DOCDIR=		share/doc/emacs20-dl-canna
DLCANNA_VER=	1.2
# hack to allow parallel build to work
.if defined(PARALLEL_PACKAGE_BUILD)
BUILD_DEPENDS+=	gmake:${PORTSDIR}/devel/gmake \
		autoconf:${PORTSDIR}/devel/autoconf
.endif

post-install:
.if !defined(NOPORTDOCS)
	@[ -d ${PREFIX}/${DOCDIR} ] || ${MKDIR} ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/README.ja ${PREFIX}/${DOCDIR}
	@${INSTALL_DATA} ${WRKSRC}/ChangeLog ${PREFIX}/${DOCDIR}
.endif

.include <bsd.port.mk>

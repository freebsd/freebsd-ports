# New ports collection makefile for:	GNU emacs
# Date created:		29 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	${EMACS_VER}
PORTREVISION=	3
CATEGORIES+=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

PATCH_SITES=		${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	shige/emacs
PATCHFILES=		emacs-20.7-linespace-patch.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GNU editing macros

USE_AUTOCONF_VER=213
USE_GMAKE=	yes
EMACS_VER=	20.7
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x=no --with-pop
.else
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	yes
.endif
CONFIGURE_ARGS+=	--with-line-space

MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		emacs.1 etags.1 ctags.1
PLIST_SUB=	EMACS_VER=${EMACS_VER} EMACS_ARCH=${CONFIGURE_TARGET}

RECOMPILE_ELS=	dired.el startup.el

pre-build:
	${RM} -rf ${WRKSRC}/info/*

post-build:
# to rebuild emacs because startup.elc should be updated
	@(cd ${WRKSRC}/lisp; \
		${WRKSRC}/src/emacs -batch -q -no-init-file \
			-f batch-byte-compile ${RECOMPILE_ELS} ; \
	)
	@${RM} -f ${WRKSRC}/src/emacs ${WRKSRC}/src/emacs-${EMACS_VER}*
	@(cd ${BUILD_WRKSRC}; \
		${SETENV} ${MAKE_ENV} \
		${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET} ;\
	)

.include <bsd.port.mk>

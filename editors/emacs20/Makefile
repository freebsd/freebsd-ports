# New ports collection makefile for:	GNU emacs
# Date created:		29 October 1994
# Whom:			jkh
#
# $FreeBSD$
#

PORTNAME=	emacs
PORTVERSION=	20.7
CATEGORIES+=	editors ipv6
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	ports@FreeBSD.org

USE_AUTOCONF=	yes
USE_GMAKE=	yes
CONFIGURE_TARGET=	${MACHINE_ARCH}--freebsd
.if defined(WITHOUT_X11)
CONFIGURE_ARGS=	--with-x=no --with-pop
.else
CONFIGURE_ARGS=	--with-x-toolkit --with-pop
USE_XLIB=	yes
.endif

MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		emacs.1 etags.1 ctags.1
PLIST_SUB=	EMACS_VER=20.7 EMACS_ARCH=${CONFIGURE_TARGET}
#WRKSRC=		${WRKDIR}/emacs-20.7

pre-build:
	${RM} -rf ${WRKSRC}/info/*

.include <bsd.port.mk>

# New ports collection makefile for:	GNU emacs
# Version required:	20.3
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.37 1999/01/27 07:41:11 fenner Exp $
#

DISTNAME=	emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	emacs

MAINTAINER=	jseger@FreeBSD.org

USE_AUTOCONF=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
EMACS_ARCH=	${MACHINE_ARCH}--freebsd
CONFIGURE_ARGS=	${EMACS_ARCH} --with-x-toolkit --with-pop

MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		emacs.1 etags.1 ctags.1
PLIST_SUB=	EMACS_VER=20.3 EMACS_ARCH=${EMACS_ARCH}

.if defined(USE_XPGLIB)
.if (${USE_XPGLIB} == "YES")
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

pre-build:
	${RM} -rf ${WRKSRC}/info/*

.include <bsd.port.mk>

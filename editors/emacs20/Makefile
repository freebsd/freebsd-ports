# New ports collection makefile for:	GNU emacs
# Version required:	20.3
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.33 1998/09/01 07:11:31 asami Exp $
#

DISTNAME=	emacs-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

MAINTAINER=	jseger@FreeBSD.org

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit --with-pop
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
MAN1=		emacs.1 etags.1 ctags.1
PLIST_SUB=	EMACS_VER=20.3

.if defined(USE_XPGLIB)
.if (${USE_XPGLIB} == "YES")
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

pre-build:
	${RM} -rf ${WRKSRC}/info/*

.include <bsd.port.mk>

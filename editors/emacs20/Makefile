# New ports collection makefile for:	GNU emacs
# Version required:	20.3
# Date created:		29 October 1994
# Whom:			jkh
#
# $Id: Makefile,v 1.31 1997/12/17 01:31:17 jseger Exp $
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

pre-build:
	${RM} -rf ${WRKSRC}/info/*

.include <bsd.port.mk>

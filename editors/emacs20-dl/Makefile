# New ports collection makefile for:	GNU emacs with dl
# Version required:	20.3
# Date created:		10 October 1998
# Whom:			shige
#
# $Id: Makefile,v 1.2 1998/12/17 09:08:09 asami Exp $
#

DISTNAME=	emacs-20.3
PKGNAME=	emacs-dl-20.3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_GNU}

PATCH_SITES=	ftp://ftp.jaist.ac.jp/pub/GNU/elisp/emacs-20-dl/
PATCHFILES=	emacs-20.3-dl.diff
PATCH_DIST_STRIP= -p1

MAINTAINER=	shige@kuis.kyoto-u.ac.jp

RUN_DEPENDS=	emacs-20.3:${PORTSDIR}/editors/emacs20

GNU_CONFIGURE=	yes
USE_XLIB=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS=	i386--freebsd --with-x-toolkit --with-pop
MAKE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
EMACS_VER=	20.3
PLIST_SUB=	EMACS_VER=${EMACS_VER}

.if defined(USE_XPGLIB)
.if (${USE_XPGLIB} == "YES")
CONFIGURE_ARGS+=	--with-xpg4
.endif
.endif

pre-build:
	@${RM} -rf ${WRKSRC}/info/*

do-install:
	@${INSTALL} -c -s -m 555 -o root -g wheel ${WRKSRC}/src/emacs ${PREFIX}/bin/emacs-dl-${EMACS_VER}

.include <bsd.port.mk>

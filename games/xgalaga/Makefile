# New ports collection makefile for:	xgalaga
# Version required:	1.6c
# Date created:		27 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.5 1997/09/06 05:32:33 max Exp $
#

DISTNAME=	xgalaga-1.6c
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	games

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	Xpm\\.4\\.:${PORTSDIR}/graphics/xpm

USE_IMAKE=	yes
NO_INSTALL_MANPAGES=	yes

EXTRA_PATCH=	patch-ab

nosound:
	@echo "Okay, making a quiet version of xgalaga...."
	@cp ${FILESDIR}/${EXTRA_PATCH} ${PATCHDIR}
	@${MAKE} ${.MAKEFLAGS} all

pre-clean:
	@rm -f ${PATCHDIR}/${EXTRA_PATCH}

pre-patch:
	@if [ ! -f ${PATCHDIR}/${EXTRA_PATCH} ]; then \
	  echo "*****************************************************" ; \
	  echo "* Note that you can build a version of xgalaga that *" ; \
	  echo "* doesn't use the sound driver by typing            *" ; \
	  echo "* \"make nosound\"                                    *" ; \
	  echo "* following a \"make clean\".                         *" ; \
	  echo "* Try it if you don't have a sound card and are     *" ; \
	  echo "* getting core dumps.                               *" ; \
	  echo "*****************************************************" ; \
	fi

.include <bsd.port.mk>


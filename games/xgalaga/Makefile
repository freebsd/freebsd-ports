# New ports collection makefile for:	xgalaga
# Version required:	1.6b
# Date created:		27 August 1995
# Whom:			asami
#
# $Id: Makefile,v 1.1.1.1 1995/08/28 07:43:37 asami Exp $
#

DISTNAME=	xgalaga-1.6b
CATEGORIES+=	games
MASTER_SITES=	ftp://crl.dec.com/pub/X11/contrib/games/

MAINTAINER=	asami@FreeBSD.ORG

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


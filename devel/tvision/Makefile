# New ports collection makefile for:	tvision
# Version required:			0.6
# Date created:				16 February 1997
# Whom:					Sandro Sigala
#
# $Id: Makefile,v 1.6 1998/09/16 22:34:37 vanilla Exp $
#

DISTNAME=	tvision-0.6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.vix.com/guests/ssigala/pub/tvision/

MAINTAINER=	ssigala@globalnet.it

BROKEN_ELF=	library names

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CXXFLAGS="$(CFLAGS)"

pre-install:
	@if [ ! -f ${PREFIX}/info/dir ]; then \
	  ${SED} -ne '1,/Menu:/p' /usr/share/info/dir > ${PREFIX}/info/dir; \
	 fi

.include <bsd.port.mk>

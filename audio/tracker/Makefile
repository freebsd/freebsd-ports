# New ports collection makefile for:    tracker
# Version required:     4.33
# Date created:         2 Oct 1994
# Whom:                 swallace
#
# $Id: Makefile,v 1.20 1995/05/11 18:12:39 ache Exp $
#

DISTNAME=       tracker
PKGNAME=        tracker-4.33
CATEGORIES+=	audio
MASTER_SITES=   ftp://ftp.ens.fr/pub/dmi/users/espie/beta/
DISTFILES=      tracker-4.33.tar.Z

MAINTAINER=     ache@FreeBSD.ORG

USE_GMAKE=      yes
MAKE_FLAGS=     MACHINE=freebsd CC=cc INSTALL=install -f
INSTALL_TARGET= install install.man

.include <bsd.port.mk>

# New ports collection makefile for:    gshar+gunshar
# Version required:     4.1.4
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1995/04/12 04:53:52 asami Exp $
#
DISTNAME=       sharutils-4.1.4
CATEGORIES+=	archivers
MASTER_SITES=   ftp://ftp.iro.umontreal.ca/pub/contrib/pinard/gnu/

MAINTAINER=     ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode --prefix=${PREFIX}
INSTALL_TARGET= install install-man

.include <bsd.port.mk>

# New ports collection makefile for:    gshar+gunshar
# Version required:     4.1.4
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.7 1996/08/16 14:38:14 peter Exp $
#
DISTNAME=       sharutils-4.1.4
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.iro.umontreal.ca/pub/contrib/pinard/gnu/

MAINTAINER=     ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode --prefix=${PREFIX}
INSTALL_TARGET= install install-man

post-patch:
	@touch ${WRKSRC}/stamp-cod
	@touch ${WRKSRC}/sharutils.cod
	@touch ${WRKSRC}/locale.c

.include <bsd.port.mk>

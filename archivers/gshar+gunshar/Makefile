# New ports collection makefile for:    gshar+gunshar
# Version required:     4.1.4
# Date created:         28 Dec 1994
# Whom:                 ache
#
# $Id: Makefile,v 1.8 1996/11/12 02:17:25 obrien Exp $
#
DISTNAME=       sharutils-4.1.4
CATEGORIES=	archivers
MASTER_SITES=   ftp://ftp.iro.umontreal.ca/pub/contrib/pinard/gnu/

MAINTAINER=     ache@FreeBSD.ORG

GNU_CONFIGURE=  yes
CONFIGURE_ARGS= --program-prefix=g --disable-uucode --prefix=${PREFIX}
INSTALL_TARGET= install install-man
MAN1=		gshar.1 gunshar.1

post-patch:
	@touch ${WRKSRC}/stamp-cod
	@touch ${WRKSRC}/sharutils.cod
	@touch ${WRKSRC}/locale.c

.include <bsd.port.mk>

# New ports collection makefile for:	libffi
# Version required:     1.18
# Date created:		14, June, 1998
# Whom:			Horance Chou <horance@freedom.ie.cycu.edu.tw>
#
# $Id: Makefile,v 1.3 1998/10/20 01:35:24 steve Exp $
#

DISTNAME=       libffi-1.18
CATEGORIES=	devel
MASTER_SITES=   ftp://ftp.cygnus.com:/pub/green/

MAINTAINER=     horance@freedom.ie.cycu.edu.tw

VERSION!=	sysctl -n kern.osreldate
.if ${VERSION} < 300000
BROKEN=		undefined symbol in ffitest
.endif

GNU_CONFIGURE=  yes
WRKSRC=         ${WRKDIR}/${PKGNAME}
ALL_TARGET=     test

.include <bsd.port.mk>

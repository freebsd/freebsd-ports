# New ports collection makefile for:   newosaka
# Version required:    1.0
# Date created:        20 January 1997
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1997/09/14 21:35:24 max Exp $
#

DISTNAME=	newosaka
PKGNAME=	ja-newosaka-1.0
CATEGORIES+=	japanese
MASTER_SITES=	ftp://ports.jp.freebsd.org/pub/incoming/distfiles/
DISTFILES=	new-osaka.tar.gz

MAINTAINER=	nacai@iname.com

do-build:
	(cd ${WRKSRC}; ${CC} ${CFLAGS} -o osaka osaka.c -I${WRKSRC})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/osaka ${PREFIX}/bin

.include <bsd.port.mk>

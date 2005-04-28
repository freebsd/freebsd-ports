# New ports collection makefile for: typespeed
# Date created:        06 September 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	typespeed
PORTVERSION=	0.4.4
CATEGORIES=	games
MASTER_SITES=	http://ls.purkki.org/typespeed/
DISTNAME=	typespeed-${PORTVERSION}

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Test your typing speed, and get your fingers\' CPS

MAN1=		typespeed.1

USE_REINPLACE=	yes
USE_GETOPT_LONG=	yes

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(/etc\)|${PREFIX}\1|' \
		${WRKSRC}/typespeed.h

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

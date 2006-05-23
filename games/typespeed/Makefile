# New ports collection makefile for: typespeed
# Date created:        06 September 2003
# Whom:                refugee
#
# $FreeBSD$
#

PORTNAME=	typespeed
PORTVERSION=	0.4.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://tobias.eyedacor.org/typespeed/ \
		http://critical.ch/distfiles/
DISTNAME=	typespeed-${PORTVERSION}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Test your typing speed, and get your fingers\' CPS

MAN1=		typespeed.1

USE_GETOPT_LONG=	yes

MAKE_ENV=	CPPFLAGS="${CPPFLAGS}" LFLAGS="${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|\(/etc\)|${PREFIX}\1|' \
		${WRKSRC}/typespeed.h

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

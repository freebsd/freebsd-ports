# New ports collection makefile for:	xpenguins
# Date created:				24 January 2001
# Whom:				`	lyngbol@candid.dk
#
# $FreeBSD$
#

PORTNAME=	xpenguins
PORTVERSION=	1.2
CATEGORIES=	games
MASTER_SITES=	http://xpenguins.seul.org/

MAINTAINER=	lyngbol@candid.dk

USE_X_PREFIX=	yes
USE_XPM=	yes
USE_GMAKE=	yes

MAN1=		xpenguins.1

pre-build:
	${PERL} -pi.orig -e "s@-L/usr/local/lib@@g; \
			     s@-I/usr/local/include@@g" ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xpenguins $(PREFIX)/bin
	${INSTALL_MAN} ${WRKSRC}/xpenguins.1 $(PREFIX)/man/man1

.include <bsd.port.mk>

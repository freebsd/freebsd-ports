# New ports collection makefile for:	backfract
# Date created:		8 August 2000
# Whom:			Patrick Gardella <patrick@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	backfract
PORTVERSION=	1.1.2
CATEGORIES=	graphics
MASTER_SITES=	http://www.inetarena.com/~wms/comp/backfract/

MAINTAINER=	patrick@FreeBSD.org

GNU_CONFIGURE=	yes
USE_X_PREFIX=	yes
NO_INSTALL_MANPAGE=	yes
ALL_TARGET= 	# none

pre-configure:
	${PERL} -pi -e "s@-O3@${CFLAGS}@g" ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/backfract ${PREFIX}/bin

.include <bsd.port.mk>

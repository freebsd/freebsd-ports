# New ports collection makefile for:	kuake
# Date created:			Thu Mar 11 21:51:00 CET 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	kuake
PORTVERSION=	0.3
PORTREVISION=	11
CATEGORIES=	deskutils kde
MASTER_SITES=	http://199.231.140.154/software/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE konsole application acting like the Quake-console

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool

CONFIGURE_ENV=	LDFLAGS="${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||g; s|-lpthread|${PTHREAD_LIBS}|g' \
		${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>

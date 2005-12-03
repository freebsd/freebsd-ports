# Ports collection Makefile for:	gnuitar
# Date created:				3 Dec 2005
# Whom:					Gabor Kovesdan
# $FreeBSD$

PORTNAME=		gnuitar
PORTVERSION=		0.3.2
CATEGORIES=		audio multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	The real-time guitar processor

USE_X_PREFIX=	YES
USE_GNOME=	gtk20 glib20
WANT_GNOME=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=--with-gtk2 \
		--enable-clip-everywhere \
		--enable-float

pre-fetch:
	@${CAT} pkg-message

.include <bsd.port.mk>

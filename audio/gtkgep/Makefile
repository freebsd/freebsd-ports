# New ports collection makefile for:	GtkGEP
# Date created:				Sun Jan 26 19:15:57 CST 2003
# Whom:					Mark Linimon <linimon@lonesome.com>
#
# $FreeBSD$
#

PORTNAME=	gtkgep
PORTVERSION=	0.2.3
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://finarfinek.republika.pl/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A guitar effects processor for GTK

DEPRECATED=	Abandonware
EXPIRATION_DATE=	2011-09-01

USE_GNOME=	gnometarget gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -fPIC" LDFLAGS="${PTHREAD_LIBS}"
PLIST_SUB=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>

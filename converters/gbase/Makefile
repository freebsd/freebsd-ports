# New ports collection makefile for:	gbase
# Date created:				Fri Sep  7 22:08:24 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	gbase
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	converters
MASTER_SITES=	http://www.fluxcode.net/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program to convert between the 4 common bases used in programming

OPTIONS=	GTK2 "GTK+-2 support" off

USE_GNOME=	pkgconfig

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_GTK2)
USE_GNOME+=	gtk12
GTK_CFLAGS=	`pkg-config --cflags gtk+-2.0`
GTK_LIBS=	`pkg-config --libs gtk+-2.0`
.else
USE_GNOME+=	gtk12
GTK_CFLAGS=	`pkg-config --cflags gtk+`
GTK_LIBS=	`pkg-config --libs gtk+`
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|(i == argc)|(i+1 == argc)|' ${WRKSRC}/${PORTNAME}.c

do-build:
	cd ${WRKSRC}; ${CC} ${CFLAGS} ${GTK_CFLAGS} ${PORTNAME}.c \
		-o ${PORTNAME} ${GTK_LIBS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

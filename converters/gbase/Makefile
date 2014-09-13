# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	gbase
PORTVERSION=	0.5
PORTREVISION=	7
CATEGORIES=	converters
MASTER_SITES=	http://www.fluxcode.net/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program to convert between the 4 common bases used in programming

LICENSE=	ART10

OPTIONS_DEFINE=	GTK2

PLIST_FILES=	bin/${PORTNAME}
USES=		pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGTK2}
USE_GNOME+=	gtk20
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
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	modplugplay
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line music mod player using libmodplug

LICENSE=	GPLv2

LIB_DEPENDS=	libmodplug.so:audio/libmodplug

PLIST_FILES=	bin/modplugplay man/man1/modplugplay.1.gz

CFLAGS+=	-I${LOCALBASE}/include/libmodplug -L${LOCALBASE}/lib
LDFLAGS+=	-lmodplug

do-build:
	${CXX} ${WRKSRC}/${PORTNAME}.c ${CFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

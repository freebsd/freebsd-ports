# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	modplugplay
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://gnu.ethz.ch/linuks.mine.nu/modplugplay/ \
		http://critical.ch/distfiles/ \
		http://energy.critical.ch/distfiles/

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Command-line music mod player using libmodplug

LICENSE=	GPLv2

LIB_DEPENDS=	modplug.1:${PORTSDIR}/audio/libmodplug

MAN1=		modplugplay.1
PLIST_FILES=	bin/modplugplay

CFLAGS+=	-I${LOCALBASE}/include/libmodplug -L${LOCALBASE}/lib
LDFLAGS+=	-lmodplug

do-build:
	${CXX} ${WRKSRC}/${PORTNAME}.c ${CFLAGS} ${LDFLAGS} \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MAN1} ${PREFIX}/man/man1

.include <bsd.port.mk>

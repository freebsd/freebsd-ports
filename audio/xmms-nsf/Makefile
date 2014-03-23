# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-nsf
PORTVERSION=	0.0.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://optronic.sourceforge.net/files/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS input-plugin for playing Nintendo(TM) NSF audio files

LICENSE=	GPLv2

DEPRECATED=	Abandonware, please consider using multimedia/audacious instead
EXPIRATION_DATE=	2014-04-27

BUILD_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89

ONLY_FOR_ARCHS=	i386 amd64

CFLAGS+=	-fPIC

PLIST_FILES=	lib/xmms/Input/libnsf.a \
		lib/xmms/Input/libnsf.la \
		lib/xmms/Input/libnsf.so

SUB_FILES=	pkg-message
SUB_LIST=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/nes/nestypes.h
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	xmms-nsf
PORTVERSION=	0.0.3
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	http://optronic.sourceforge.net/files/ \
		LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	XMMS input-plugin for playing Nintendo(TM) NSF audio files

LICENSE=	GPLv2

BUILD_DEPENDS=	xmms:multimedia/xmms
RUN_DEPENDS=	xmms:multimedia/xmms

GNU_CONFIGURE=	yes
USES=		libtool
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
CONFIGURE_ARGS=	--disable-static --with-pic

ONLY_FOR_ARCHS=	i386 amd64

PLIST_FILES=	lib/xmms/Input/libnsf.so

SUB_FILES=	pkg-message
SUB_LIST=	VERSION=${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|' \
		${WRKSRC}/src/nes/nestypes.h

.include <bsd.port.mk>

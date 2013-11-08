# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-audiofile
PORTVERSION=	0.1
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	http://www.68k.org/~michael/xmms/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS plugin to allow playing libaudiofile supported files

LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libaf.so
USES=		gmake
NO_STAGE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGURE_ENV=	LIBS="${LIBS} ${PTHREAD_LIBS}"
CFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_CFLAGS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =|CFLAGS = @CFLAGS@|; \
		s|LIBS = @AUDIOFILE_LIBS@|LIBS = @AUDIOFILE_LIBS@ @LIBS@|' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/configure

.include <bsd.port.mk>

# New ports collection makefile for:	xmms-audiofile
# Date created:				4 Feb 2003
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-audiofile
PORTVERSION=	0.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://www.68k.org/~michael/xmms/

MAINTAINER=	dyeske@yahoo.com
COMMENT=	XMMS plugin to allow playing libaudiofile supported files

LIB_DEPENDS=	audiofile.0:${PORTSDIR}/audio/libaudiofile
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libaf.so
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib ${PTHREAD_CFLAGS}" \
		LIBS="${LIBS} ${PTHREAD_LIBS}"

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CFLAGS =|CFLAGS = @CFLAGS@|; \
		s|LIBS = @AUDIOFILE_LIBS@|LIBS = @AUDIOFILE_LIBS@ @LIBS@|' \
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>

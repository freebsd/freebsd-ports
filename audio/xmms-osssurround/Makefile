# New ports collection makefile for:	xmms-surround
# Date created:		24 July 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	xmms-osssurround
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmms-a52dec
DISTNAME=	xmms-a52dec-1.0

MAINTAINER=	ports@FreeBSD.org
COMMENT=	OSSSuround adds Surround Sound capabilities to XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

USE_BZIP2=	yes
USE_X_PREFIX=	yes
CFLAGS+=	-fPIC `xmms-config --cflags`

BUILD_WRKSRC=	${WRKSRC}/OSSSurround-${PORTVERSION}

PLIST_FILES=	lib/xmms/Output/libOSSSurround.so

do-build:
	cd ${BUILD_WRKSRC} && \
	 ${CC} ${CFLAGS} -c *.c && \
	 ${CC} -shared -olibOSSSurround.so about.o audio.o configure.o convert.o init.o mixer.o OSS.o

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/OSSSurround-0.1/libOSSSurround.so \
		${PREFIX}/lib/xmms/Output/

.include <bsd.port.mk>

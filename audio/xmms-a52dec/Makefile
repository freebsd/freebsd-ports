# New ports collection makefile for:	xmms-a52dec
# Date created:		24 July 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	xmms-a52dec
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmms-a52dec

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A52 (aka AC3) decoder plugin for XMMS

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms \
		a52.0:${PORTSDIR}/audio/liba52
RUN_DEPENDS=	${X11BASE}/lib/xmms/Output/libOSSSurround.so:${PORTSDIR}/audio/xmms-osssurround

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
CFLAGS+=	`xmms-config --cflags` -L${LOCALBASE}/lib

.include <bsd.port.pre.mk>
.if ${ARCH} == "amd64"
CFLAGS=	-fPIC
.endif

PLSIT_FILES=	lib/xmms/Input/liba52dec.so

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -shared -o liba52dec.so xmms-a52dec.c -la52

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/liba52dec.so ${PREFIX}/lib/xmms/Input/

.include <bsd.port.post.mk>

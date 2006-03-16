# New ports collection makefile for:    gxmms2
# Date created:				03 Mar 2006
# Whom:				  	Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	gxmms2
PORTVERSION=	0.6.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://wejp.mooo.com/wejp/xmms2/

MAINTAINER=	alex@foxybanana.com
COMMENT=	A GTK2 based XMMS2 client, written in C

BUILD_DEPENDS=	${LOCALBASE}/lib/libxmmsclient.so:${PORTSDIR}/audio/xmms2

USE_X_PREFIX=	yes
USE_GNOME=	gtk20

ALL_TARGET=	${PORTNAME}
PLIST_FILES=	bin/gxmms2

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		does not build on FreeBSD 4.x
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.post.mk>

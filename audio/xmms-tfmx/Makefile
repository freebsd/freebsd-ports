# New ports collection makefile for:	xmms-tfmx
# Date created:			21 May 2000
# Whom:				Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	xmms-tfmx
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS Input plugin for playing TFMX tunes

LIB_DEPENDS=	xmms.4:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libtfmx.so
USE_X_PREFIX=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes

.include <bsd.port.mk>

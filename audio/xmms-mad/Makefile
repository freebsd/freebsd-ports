# New ports collection makefile for:	xmms-mad
# Date created:				30 Aug 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-mad
PORTVERSION=	0.1.1
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	xmms-mad

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS input plugin that uses libmad

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/mad
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Input/libxmmsmad.so
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CFLAGS="${CFLAGS} -L${LOCALBASE}/lib"

.include <bsd.port.mk>

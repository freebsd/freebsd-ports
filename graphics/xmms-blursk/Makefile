# New ports collection makefile for:	xmms-blursk
# Date created:				19 Aug 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	blursk
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.pdx.edu/~kirkenda/blursk/
PKGNAMEPREFIX=	xmms-
DISTNAME=	Blursk-${PORTVERSION}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	A XMMS plugin inspired by "Blur Scope"

BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

PLIST_FILES=	lib/xmms/Visualization/libblursk.so
USE_X_PREFIX=	yes
USE_GNOME=	gtk12
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} ${CFLAGS} ${PTHREAD_CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT} \
		${BUILD_WRKSRC}/Makefile.in

.include <bsd.port.mk>

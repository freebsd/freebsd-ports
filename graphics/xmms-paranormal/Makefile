# New ports collection makefile for:	xmms-paranormal
# Date created:				25 Apr 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-paranormal
PORTVERSION=	0.2.0
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	paranormal
DISTNAME=	paranormal-${PORTVERSION:S/.p/pre/}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An adaptation of the "OpenGL Spectrum Analyzer" from XMMS

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include/libxml2/libxml"

GNU_CONFIGURE=	yes
USE_SDL=	sdl
INSTALLS_SHLIB=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_MESA=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|SDL/|SDL11/|g' \
		${BUILD_WRKSRC}/xmms.c

.include <bsd.port.mk>

# New ports collection makefile for:	xmms-paranormal
# Date created:				25 Apr 2002
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	xmms-paranormal
PORTVERSION=	0.2.0
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	paranormal
DISTNAME=	paranormal-${PORTVERSION:S/.p/pre/}

MAINTAINER=	dyeske@yahoo.com
COMMENT=	An adaptation of the "OpenGL Spectrum Analyzer" from XMMS

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2 \
		glut.4:${PORTSDIR}/graphics/libglut
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

CONFIGURE_ENV+=	CFLAGS="-I${LOCALBASE}/include/libxml2/libxml"

GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes
USE_X_PREFIX=	yes

post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>

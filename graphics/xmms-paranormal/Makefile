# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	xmms-paranormal
PORTVERSION=	0.2.0
PORTREVISION=	12
CATEGORIES=	graphics
MASTER_SITES=	SF/paranormal/old-paranormal-xmms/${PORTVERSION}
DISTNAME=	paranormal-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adaptation of the "OpenGL Spectrum Analyzer" from XMMS

LIB_DEPENDS=	xml2:${PORTSDIR}/textproc/libxml2
BUILD_DEPENDS=	xmms-config:${PORTSDIR}/multimedia/xmms
RUN_DEPENDS=	xmms:${PORTSDIR}/multimedia/xmms

CFLAGS+=	-I${LOCALBASE}/include/libxml2/libxml

USE_GL=		glut
GNU_CONFIGURE=	yes
USE_SDL=	sdl
USE_LDCONFIG=	yes
USE_GNOME=	gtk12
USE_GMAKE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e '/objformat=/s|=.*|=elf|' ${WRKSRC}/ltconfig

.include <bsd.port.mk>

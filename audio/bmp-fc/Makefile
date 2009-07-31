# New ports collection makefile for:	bmp-fc
# Date created:				13 Aug 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	bmp-fc
PORTVERSION=	0.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	xmms-fc

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A Future Composer input plug-in for beep-media-player

LIB_DEPENDS=	beep.2:${PORTSDIR}/multimedia/beep-media-player

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	lib/bmp/Input/libfc.so lib/bmp/Input/libfc.la

post-patch:
	@${REINPLACE_CMD} -e 's|\(objformat=\).*|\1elf|' ${WRKSRC}/configure

.include <bsd.port.mk>

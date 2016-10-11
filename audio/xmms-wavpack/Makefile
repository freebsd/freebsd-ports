# $FreeBSD$

PORTNAME=	xmms-wavpack
PORTVERSION=	1.0.3
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XMMS input plugin to play WavPack files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libwavpack.so:audio/wavpack \
		libxmms.so:multimedia/xmms

USES=		iconv libtool localbase pkgconfig tar:bzip2
GNU_CONFIGURE=	yes

PLIST_FILES=	lib/xmms/Input/libwavpack.so

.include <bsd.port.mk>

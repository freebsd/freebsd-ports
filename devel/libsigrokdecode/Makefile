# Created by: Uffe Jakobsen <uffe@uffe.org>
# $FreeBSD$

PORTNAME=	libsigrokdecode
PORTVERSION=	0.3.0
CATEGORIES=	devel
MASTER_SITES=	http://sigrok.org/download/source/libsigrokdecode/

MAINTAINER=	uffe@uffe.org
COMMENT=	Framework for hardware logic analyzers, protocol decoders library

LICENSE=	GPLv3

USE_PYTHON=	3
GNU_CONFIGURE=	yes
USE_GNOME=	glib20
USES=		gmake pathfix libtool pkgconfig
MAKE_JOBS_UNSAFE=	yes
USE_LDCONFIG=	yes

# Workaround for libusb not knowing LIBUSB_CLASS_APPLICATION
CFLAGS+=	-DLIBUSB_CLASS_APPLICATION=0xfe

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsigrokdecode.so

.include <bsd.port.mk>

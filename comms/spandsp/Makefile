# Created by: wlloyd@slap.net
# $FreeBSD$

PORTNAME=	spandsp
PORTVERSION=	0.0.5
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.soft-switch.org/downloads/spandsp/ \
		http://www.soft-switch.org/downloads/spandsp/old/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSP library and software FAX machine

LIB_DEPENDS=	libtiff.so:${PORTSDIR}/graphics/tiff

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf automake libtoolize
AUTOMAKE_ARGS=	--add-missing
USES=		gmake libtool tar:tgz
INSTALL_TARGET=	install-strip

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

USE_LDCONFIG=	yes

CONFLICTS=	spandsp-devel-[0-9]*

.include <bsd.port.mk>

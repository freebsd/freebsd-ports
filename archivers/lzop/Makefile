# New ports collection makefile for:	lzop
# Date created:				Fri 2 June 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	lzop
PORTVERSION=	1.01
CATEGORIES=	archivers
MASTER_SITES=	http://www.lzop.org/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fast file compressor similar to gzip, using the LZO library

LIB_DEPENDS=	lzo.1:${PORTSDIR}/archivers/lzo

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		lzop.1
PLIST_FILES=	bin/lzop

.include <bsd.port.mk>

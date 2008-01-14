# New ports collection makefile for:	libopkele
# Date created:				28 November 2007
# Whom:					Sutra Zhou <zhoushuqun@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	libopkele
PORTVERSION=	0.3.2
CATEGORIES=	devel
MASTER_SITES=	http://kin.klever.net/dist/

MAINTAINER=	zhoushuqun@gmail.com
COMMENT=	A c++ implementation of an OpenID decentralized identity system

LIB_DEPENDS=	curl.4:${PORTSDIR}/ftp/curl \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	yes
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	"OPENSSL_CFLAGS=${CFLAGS} -l${OPENSSLINC}" \
		OPENSSL_LIBS=-L${OPENSSLLIB}

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS=	"-L${LOCALBASE}/lib"

post-patch:
	@ ${REINPLACE_CMD} -e "s|pkgconfigdir =.*|pkgconfigdir = ${PREFIX}/libdata/pkgconfig|g" \
	    ${WRKSRC}/Makefile.in

.include <bsd.port.mk>

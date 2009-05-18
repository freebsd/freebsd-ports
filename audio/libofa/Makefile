# New ports collection makefile for:	libofa
# Date created:		2006-04-01
# Whom:			Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	libofa
PORTVERSION=	0.9.3
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://www.musicdns.org/files/

MAINTAINER=	alexbl@FreeBSD.org
COMMENT=	The Open Fingerprint Architecture Library

LIB_DEPENDS=	fftw3.5:${PORTSDIR}/math/fftw3 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		curl.5:${PORTSDIR}/ftp/curl

USE_AUTOTOOLS=	libtool:15
USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

.include <bsd.port.pre.mk>

post-configure:
	@${REINPLACE_CMD} -e "s|pcdir =.*|pcdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>

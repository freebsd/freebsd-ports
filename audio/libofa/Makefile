# New ports collection makefile for:	libofa
# Date created:		2006-04-01
# Whom:			Alexander Botero-Lowry <alex@foxybanana.com>
#
# $FreeBSD$
#

PORTNAME=	libofa
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.musicdns.org/themes/musicdns_org/downloads/

MAINTAINER=	alex@foxybanana.com
COMMENT=	The Open Fingerprint Architecture Library

LIB_DEPENDS=	fftw3.4:${PORTSDIR}/math/fftw3 \
		expat.6:${PORTSDIR}/textproc/expat2 \
		curl.3:${PORTSDIR}/ftp/curl

USE_GNOME=	pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		Does not build on FreeBSD < 5.x
.endif

post-configure:
	@${REINPLACE_CMD} -e "s|pcdir =.*|pcdir = ${PREFIX}/libdata/pkgconfig|g" \
		${WRKSRC}/Makefile

.include <bsd.port.post.mk>

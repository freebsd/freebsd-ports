# New ports collection makefile for:	libaacplus
# Date created:		2010-05-18
# Whom:			takefu
#
# $FreeBSD$
#

PORTNAME=	libaacplus
PORTVERSION=	2.0.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://tipok.org.ua/downloads/media/aac+/libaacplus/:site1\
		http://217.20.164.161/~tipok/aacplus/:site1\
		http://media.wnet.ua/~tipok/aacplus/:site1\
		ftp://ftp.3gpp.org/Specs/archive/26_series/26.410/:site2\
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.410/:site2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:site1\
		26410-800.zip:site2

MAINTAINER=	takefu@airport.fm
COMMENT=	HE-AAC+ Codec as Shared Library

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

CONFLICTS=	aacplusenc-0*

USE_GNOME=	gnomehack pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool libtoolize aclocal autoheader automake
GNOME_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes

AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} \
		-I ${LOCALBASE}/share/aclocal -I ${WRKSRC}/m4
LIBTOOLIZE_ARGS=--automake

MAN1=		aacplusenc.1

OPTIONS=	FFTW3	"USE_FFTW3"		on

.include <bsd.port.options.mk>

.if !defined(WITHOUT_FFTW3)
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3\
		fftw3f:${PORTSDIR}/math/fftw3-float
CONFIGURE_ARGS+=--with-fftw3=yes \
		--with-fftw3-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-fftw3=no
.endif

pre-configure:
	@${CP} ${DISTDIR}/26410-800.zip ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's,@includedir@\/aacplus,@prefix@\/include,' ${WRKSRC}/aacplus.pc.in
	@${REINPLACE_CMD} -e 's,\/aacplus\.h,\/libaacplus\/aacplus\.h,' ${WRKSRC}/aacplus.spec.in

.include <bsd.port.mk>

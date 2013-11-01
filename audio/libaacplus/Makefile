# Created by: takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	libaacplus
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	http://media.wnet.ua/~tipok/aacplus/:site1\
		ftp://ftp.3gpp.org/Specs/archive/26_series/26.410/:site2\
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.410/:site2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:site1\
		26410-800.zip:site2

MAINTAINER=	takefu@airport.fm
COMMENT=	HE-AAC+ Codec as Shared Library

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

CONFLICTS=	aacplusenc-0*

USE_CSTD=	gnu89
USES=		pathfix pkgconfig
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool libtoolize aclocal autoheader automake
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes

AUTOMAKE_ARGS=	--add-missing
LIBTOOLIZE_ARGS=--automake

OPTIONS_DEFINE=	FFTW3
OPTIONS_DEFAULT=FFTW3

FFTW3_DESC=	Use FFTW3 library for performance

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFFTW3}
LIB_DEPENDS+=	fftw3:${PORTSDIR}/math/fftw3 \
		fftw3f:${PORTSDIR}/math/fftw3-float
CONFIGURE_ARGS+=--with-fftw3=yes --with-fftw3-prefix=${LOCALBASE}
.else
CONFIGURE_ARGS+=--with-fftw3=no
.endif

pre-configure:
	@${CP} ${DISTDIR}/26410-800.zip ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's,@includedir@\/aacplus,@prefix@\/include,' \
		${WRKSRC}/aacplus.pc.in
	@${REINPLACE_CMD} -e 's,\/aacplus\.h,\/libaacplus\/aacplus\.h,' \
		${WRKSRC}/aacplus.spec.in

.include <bsd.port.mk>

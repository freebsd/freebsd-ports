# Created by: takefu <takefu@airport.fm>
# $FreeBSD$

PORTNAME=	libaacplus
PORTVERSION=	2.0.2
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	http://tipok.org.ua/downloads/media/aacplus/libaacplus/ \
		ftp://ftp.3gpp.org/Specs/archive/26_series/26.410/:site2 \
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.410/:site2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SRC26410}:site2

MAINTAINER=	takefu@airport.fm
COMMENT=	HE-AAC+ Codec as Shared Library

LICENSE=	libaacplus
LICENSE_NAME=	3GPP
LICENSE_TEXT=	${RESTRICTED}
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept
LICENSE_DISTFILES_LGPL=	${DISTNAME}${EXTRACT_SUFX}
LICENSE_DISTFILES_3GPP=	${SRC26410}

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

CONFLICTS=	aacplusenc-0*

USE_CSTD=	gnu89
USES=		autoreconf pathfix pkgconfig libtool
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

AUTOMAKE_ARGS=	--add-missing

OPTIONS_DEFINE=	FFTW3
OPTIONS_DEFAULT=FFTW3

SRC26410=	26410-800.zip

FFTW3_DESC=	Use FFTW3 library for performance

FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
FFTW3_CONFIGURE_ON=	--with-fftw3=yes --with-fftw3-prefix=${LOCALBASE}
FFTW3_CONFIGURE_OFF=	--with-fftw3=no

pre-configure:
	@${CP} ${DISTDIR}/26410-800.zip ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's,@includedir@\/aacplus,@prefix@\/include,' \
		${WRKSRC}/aacplus.pc.in
	@${REINPLACE_CMD} -e 's,\/aacplus\.h,\/libaacplus\/aacplus\.h,' \
		${WRKSRC}/aacplus.spec.in
	@${REINPLACE_CMD} -e 's,INCLUDES,AM_CPPFLAGS,'\
		${WRKSRC}/frontend/Makefile.am ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>

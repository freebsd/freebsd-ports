PORTNAME=	libaacplus
PORTVERSION=	2.0.2
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	http://tipok.org.ua/downloads/media/aacplus/libaacplus/ \
		ftp://ftp.3gpp.org/Specs/archive/26_series/26.410/:site2 \
		https://www.3gpp.org/ftp/Specs/archive/26_series/26.410/:site2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${SRC26410}.zip:site2

MAINTAINER=	takefu@airport.fm
COMMENT=	HE-AAC+ Codec as Shared Library

LICENSE=	libaacplus
LICENSE_NAME=	3GPP
LICENSE_TEXT=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies
LICENSE_PERMS=	no-dist-mirror no-dist-sell no-pkg-mirror no-pkg-sell auto-accept

DEPRECATED=	Abandoned upstream, no new release since 2011
EXPIRATION_DATE=2021-12-31

USES=		autoreconf cpe pathfix pkgconfig libtool

USE_CSTD=	gnu89
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_UNSAFE=	yes
INSTALL_TARGET=	install-strip

CONFLICTS=	aacplusenc-0*

OPTIONS_DEFINE=	FFTW3
OPTIONS_DEFAULT=FFTW3

FFTW3_DESC=	Use FFTW3 library for performance

FFTW3_LIB_DEPENDS=	libfftw3.so:math/fftw3 \
			libfftw3f.so:math/fftw3-float
FFTW3_CONFIGURE_ON=	--with-fftw3=yes --with-fftw3-prefix=${LOCALBASE}
FFTW3_CONFIGURE_OFF=	--with-fftw3=no

LICENSE_DISTFILES_3GPP=	${SRC26410}.zip
SRC26410=	26410-g00

pre-configure:
	@${CP} ${DISTDIR}/${SRC26410}.zip ${WRKSRC}/src
	@${REINPLACE_CMD} -e 's,@includedir@\/aacplus,@prefix@\/include,' \
		${WRKSRC}/aacplus.pc.in
	@${REINPLACE_CMD} -e 's,\/aacplus\.h,\/libaacplus\/aacplus\.h,' \
		${WRKSRC}/aacplus.spec.in
	@${REINPLACE_CMD} -e 's,INCLUDES,AM_CPPFLAGS,'\
		${WRKSRC}/frontend/Makefile.am ${WRKSRC}/src/Makefile.am
	@${REINPLACE_CMD} -e 's,%%SRC26410%%,${SRC26410},g' \
		${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>

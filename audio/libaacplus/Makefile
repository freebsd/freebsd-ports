# New ports collection makefile for:	libaacplus
# Date created:		2010-05-18
# Whom:			takefu
#
# $FreeBSD$
#

PORTNAME=	libaacplus
PORTVERSION=	1.0.5
CATEGORIES=	audio
MASTER_SITES=	http://tipok.org.ua/downloads/media/aac+/libaacplus/:site1\
		http://217.20.164.161/~tipok/aacplus/:site1\
		http://media.wnet.ua/~tipok/aacplus/:site1\
		http://www.3gpp.org/ftp/Specs/archive/26_series/26.410/:site2
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX}:site1\
		26410-800.zip:site2

MAINTAINER=	takefu@airport.fm
COMMENT=	HE-AAC+ Codec as Shared Library

EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

RESTRICTED=	unclear legal status, probably need licenses from 3GPP, Via Licensing and Coding Technologies

CONFLICTS=	aacplusenc-0*

USE_GNOME=	pkgconfig
USE_GMAKE=	yes
USE_LDCONFIG=	yes
USE_AUTOTOOLS=	libtool:22 libtoolize aclocal:110 autoheader:267 automake:110
GNU_CONFIGURE=	yes

AUTOMAKE_ARGS=	--add-missing
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} \
		-I ${LOCALBASE}/share/aclocal -I ${WRKSRC}/m4
LIBTOOLIZE_ARGS=--automake
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"\
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"

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
	@${CP} ${DISTDIR}/26410-800.zip ${WRKSRC}

.include <bsd.port.mk>

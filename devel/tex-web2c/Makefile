# $FreeBSD$

PORTNAME=	web2c
PORTVERSION=	20140525
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${PORTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX implementation translating WEB to C

LIB_DEPENDS=	libopenjpeg.so:${PORTSDIR}/graphics/openjpeg15 \
		libpng.so:${PORTSDIR}/graphics/png \
		libzzip.so:${PORTSDIR}/devel/zziplib

USE_TEX=	kpathsea
USE_XORG=	pixman
USES=		pkgconfig gmake tar:xz
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES}
EXTRACT_FILES=	${DISTNAME}/build-aux \
		${DISTNAME}/libs/xpdf \
		${DISTNAME}/libs/cairo \
		${DISTNAME}/libs/pixman \
		${DISTNAME}/texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	OBSDCOMPAT_INCLUDES=-I${WRKSRC}/../../libs/obsdcompat
CONFIGURE_ARGS=	--disable-luatex \
		--disable-luajittex \
		--disable-xetex \
		--disable-aleph \
		--disable-ptex \
		--disable-eptex \
		--disable-uptex \
		--disable-euptex \
		--with-x=no \
		--without-mf-x-toolkit \
		--with-system-icu \
		--with-icu-includes=${LOCALBASE}/include \
		--with-icu-libdir=${LOCALBASE}/lib \
		--with-system-kpathsea \
		--with-kpathsea-includes=${LOCALBASE}/include \
		--with-kpathsea-libdir=${LOCALBASE}/lib \
		--with-system-libpng \
		--with-libpng-includes=${LOCALBASE}/include \
		--with-libpng-libdir=${LOCALBASE}/lib \
		--with-system-pixman \
		--with-system-zlib \
		--with-system-zziplib
CFLAGS+=	-I${LOCALBASE}/include

INFO=	web2c

pre-configure:
	for D in libs/xpdf libs/cairo; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
			CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
			LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
			${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

.include <bsd.port.mk>

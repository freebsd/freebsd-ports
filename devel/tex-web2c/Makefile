# $FreeBSD$

PORTNAME=	web2c
PORTVERSION=	20150521
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${PORTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	TeX implementation translating WEB to C

LIB_DEPENDS=	libopenjpeg.so:graphics/openjpeg15 \
		libpng.so:graphics/png \
		libzzip.so:devel/zziplib \
		libmpfr.so:math/mpfr

USES=		pathfix pkgconfig libtool tar:xz
USE_TEX=	kpathsea ptexenc
USE_XORG=	pixman
USE_GNOME=	cairo
USE_LDCONFIG=	yes
EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux \
		libs/xpdf \
		texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-luatex \
		--disable-luajittex \
		--disable-xetex \
		--disable-aleph \
		--disable-ptex \
		--disable-tex \
		--disable-latex \
		--disable-pdftex \
		--disable-eptex \
		--disable-uptex \
		--disable-euptex \
		--disable-synctex \
		--with-x=no \
		--without-mf-x-toolkit \
		--with-system-zlib \
		--with-system-zziplib
.for L in pixman cairo gmp mpfr libpng icu kpathsea ptexenc
CONFIGURE_ARGS+=--with-system-$L \
		--with-$L-include=${LOCALBASE}/include \
		--with-$L-libdir=${LOCALBASE}/lib
.endfor
CFLAGS+=	-I${LOCALBASE}/include
INSTALL_TARGET=	install-strip

INFO=	web2c

pre-configure:
	for D in libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
			CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
			LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
			${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

.include <bsd.port.mk>

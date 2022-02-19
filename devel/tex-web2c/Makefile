PORTNAME=	web2c
PORTVERSION=	${TEXLIVE_VERSION}
CATEGORIES=	devel
MASTER_SITES=	TEX_CTAN/systems/texlive/Source/
PKGNAMEPREFIX=	tex-
DISTNAME=	texlive-${PORTVERSION}-source
DIST_SUBDIR=	TeX

MAINTAINER=	tex@FreeBSD.org
COMMENT=	TeX implementation translating WEB to C

LIB_DEPENDS=	libgmp.so:math/gmp \
		libmpfr.so:math/mpfr \
		libopenjp2.so:graphics/openjpeg \
		libpng.so:graphics/png \
		libzzip.so:devel/zziplib

USES=		gnome libtool localbase pathfix pkgconfig tar:xz xorg
USE_GNOME=	cairo
USE_LDCONFIG=	yes
USE_TEX=	kpathsea ptexenc
USE_XORG=	pixman

GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-aleph \
			--disable-eptex \
			--disable-euptex \
			--disable-latex \
			--disable-luahbtex \
			--disable-luajithbtex \
			--disable-luajittex \
			--disable-luatex \
			--disable-mflua \
			--disable-mfluajit \
			--disable-pdftex \
			--disable-ptex \
			--disable-synctex \
			--disable-tex \
			--disable-uptex \
			--disable-xetex \
			--with-system-zlib \
			--with-system-zziplib \
			--with-x=no \
			--without-mf-x-toolkit
.for L in pixman cairo gmp mpfr libpng icu kpathsea ptexenc
CONFIGURE_ARGS+=	--with-$L-include=${LOCALBASE}/include \
			--with-$L-libdir=${LOCALBASE}/lib \
			--with-system-$L
.endfor

INSTALL_TARGET=	install-strip

CONFLICTS_INSTALL=	cweb

EXTRACT_AFTER_ARGS=	${EXTRACT_FILES:S,^,${DISTNAME}/,}
EXTRACT_FILES=	build-aux libs/xpdf texk/web2c
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/web2c

INFO=		web2c

post-extract:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

pre-configure:
	for D in libs/xpdf; do \
		cd ${WRKDIR}/${DISTNAME}/$$D && \
		${SETENV} CC="${CC}" CPP="${CPP}" CXX="${CXX}" \
			CFLAGS="${CFLAGS}" CPPFLAGS="${CPPFLAGS}" CXXFLAGS="${CXXFLAGS}" \
			LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
			${CONFIGURE_ENV} ${SH} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}; \
	done

.include <bsd.port.mk>

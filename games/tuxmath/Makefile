# Created by: Alejandro Pulver <alejandro@varnet.biz>
# $FreeBSD$

PORTNAME=	tuxmath
PORTVERSION=	2.0.3
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3571/ \
		http://alioth.debian.org/frs/download.php/3540/:t4k_common
DISTFILES=	${PORTNAME}_w_fonts-${PORTVERSION}${EXTRACT_SUFX} \
		${T4K_DISTFILE}:t4k_common

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educational arcade game starring Tux

LICENSE=	GPLv3 # (or later)

OPTIONS_DEFINE=	NLS SVG DOCS
OPTIONS_DEFAULT=	SVG
OPTIONS_SUB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}_w_fonts-${PORTVERSION}

USE_GNOME=	libxml2
USE_SDL=	image mixer net pango sdl
USES=		iconv gmake perl5 pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	T4K_COMMON_CFLAGS="-I${T4K_WRKSRC}/src" \
		T4K_COMMON_LIBS="${T4K_WRKSRC}/src/.libs/libt4k_common.a" \
		ac_cv_lib_m_csin=yes

CPPFLAGS+=	$$(pkg-config --cflags SDL_Pango) -I${LOCALBASE}/include \
		-DHAVE_ALPHASORT -DHAVE_SCANDIR -DHAVE_FSYNC -DICONV_CONST=""
LDFLAGS+=	$$(pkg-config --libs SDL_Pango) -L${LOCALBASE}/lib ${ICONV_LIB} -lpng15

T4K_NAME=	t4k_common
T4K_VERSION=	0.1.1
T4K_DISTFILE=	${T4K_NAME}-${T4K_VERSION}${EXTRACT_SUFX}
T4K_WRKSRC=	${WRKDIR}/${T4K_NAME}-${T4K_VERSION}

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=	gettext
NLS_LDFLAGS=	-lintl

SVG_CONFIGURE_WITH=	rsvg
SVG_USE=	GNOME=librsvg2

# use multiple make jobs for T4K_WRKSRC
_make_jobs=	-j${MAKE_JOBS_NUMBER}

post-extract:
	@${LN} -sf ${T4K_WRKSRC} ${WRKDIR}/${T4K_NAME}

post-patch:
	@${REINPLACE_CMD} -e \
		'/doc[[:space:]]/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-Wall -g |-Wall | ; \
		 s|-DDEBUG ||' ${WRKSRC}/src/Makefile.in

pre-configure:
	@(cd ${T4K_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--disable-shared ${CONFIGURE_ARGS} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}")

pre-build:
	@(cd ${T4K_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${_make_jobs} ${ALL_TARGET})

post-install:
	${LN} -s ${DATADIR}/images/status ${STAGEDIR}${DATADIR}/images/menu
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in OFL README README_DATA_LICENSES TODO changelog
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

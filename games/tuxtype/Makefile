# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	tuxtype
PORTVERSION=	1.8.1
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3270/ \
		http://alioth.debian.org/frs/download.php/3540/:t4k_common
DISTFILES=	${PORTNAME}_w_fonts-${PORTVERSION}${EXTRACT_SUFX} \
		${T4K_DISTFILE}:t4k_common

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Educational typing tutor starring Tux the Linux Penguin

LICENSE=	GPLv3 # (or later)

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

WRKSRC=		${WRKDIR}/${PORTNAME}_w_fonts-${PORTVERSION}

USES=		gmake iconv perl5 pkgconfig
USE_GNOME=	libxml2
USE_SDL=	image mixer net pango sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	T4K_COMMON_CFLAGS="-I${T4K_WRKSRC}/src" \
		T4K_COMMON_LIBS="${T4K_WRKSRC}/src/.libs/libt4k_common.a" \
		ac_cv_lib_m_csin=yes

CPPFLAGS+=	$$(pkg-config --cflags SDL_Pango) -I${LOCALBASE}/include \
		-DHAVE_ALPHASORT -DHAVE_SCANDIR -DHAVE_FSYNC -DICONV_CONST=""
LDFLAGS+=	$$(pkg-config --libs SDL_Pango) -L${LOCALBASE}/lib ${ICONV_LIB}

OPTIONS_DEFINE=		DOCS NLS SVG
OPTIONS_DEFAULT=	SVG
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SVG_USE_GNOME=		librsvg2
SVG_CONFIGURE_WITH=	rsvg

T4K_NAME=	t4k_common
T4K_VERSION=	0.1.1
T4K_DISTFILE=	${T4K_NAME}-${T4K_VERSION}${EXTRACT_SUFX}
T4K_WRKSRC=	${WRKDIR}/${T4K_NAME}-${T4K_VERSION}

post-extract:
	@${LN} -sf ${T4K_WRKSRC} ${WRKDIR}/${T4K_NAME}

post-patch:
.for i in convert_utf.h mysetenv.h practice.c
	@${ECHO_CMD} >> ${WRKSRC}/src/${i}
.endfor
	@${REINPLACE_CMD} -e \
		'/-R$$found_dir/s|^|#|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/[[:blank:]]VERSION/d' ${WRKSRC}/config.h.in
	@${REINPLACE_CMD} -e \
		'/doc[[:blank:]]/d' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh| ; \
		 s|^sed |gsed |' ${WRKSRC}/data/scripts/sed-linux.sh
	@${REINPLACE_CMD} -e \
		's|-Wall -g |-Wall | ; \
		 s|-DDEBUG ||' ${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e \
		's|<iconv.h>|"config.h"| ; \
		 /<libintl.h>/d' ${WRKSRC}/src/globals.h

pre-configure:
	@(cd ${T4K_WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./configure \
		--disable-shared ${CONFIGURE_ARGS} CC="${CC}" CXX="${CXX}" \
		CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}")

pre-build:
	@(cd ${T4K_WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} -j${MAKE_JOBS_NUMBER} ${ALL_TARGET})

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in AUTHORS ChangeLog OFL README TODO
	(cd ${WRKSRC}/doc && ${INSTALL_DATA} ${i} ${STAGEDIR}${DOCSDIR})
.endfor
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/en
	(cd ${WRKSRC}/doc/en && ${INSTALL_DATA} *.html ${STAGEDIR}${DOCSDIR}/en)

.include <bsd.port.mk>

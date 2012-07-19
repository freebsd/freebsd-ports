# New ports collection makefile for:	tuxtype
# Date created:				Mon Aug  6 21:53:03 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	tuxtype
PORTVERSION=	1.8.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://alioth.debian.org/frs/download.php/3270/ \
		http://alioth.debian.org/frs/download.php/3540/:t4k_common
DISTFILES=	${PORTNAME}_w_fonts-${PORTVERSION}${EXTRACT_SUFX} \
		${T4K_DISTFILE}:t4k_common

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An educational typing tutor starring Tux the Linux Penguin

LICENSE=	GPLv3 # (or later)

BUILD_DEPENDS=	gsed:${PORTSDIR}/textproc/gsed

OPTIONS_DEFINE=	NLS SVG DOCS
OPTIONS_DEFAULT=	SVG

WRKSRC=		${WRKDIR}/${PORTNAME}_w_fonts-${PORTVERSION}

USE_GNOME=	libxml2
USE_SDL=	image mixer net pango sdl
USE_PERL5=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	T4K_COMMON_CFLAGS="-I${T4K_WRKSRC}/src" \
		T4K_COMMON_LIBS="${T4K_WRKSRC}/src/.libs/libt4k_common.a" \
		ac_cv_lib_m_csin=yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	$$(pkg-config --cflags SDL_Pango) -I${LOCALBASE}/include \
		-DHAVE_ALPHASORT -DHAVE_SCANDIR -DHAVE_FSYNC -DICONV_CONST=""
LDFLAGS+=	$$(pkg-config --libs SDL_Pango) -L${LOCALBASE}/lib

T4K_NAME=	t4k_common
T4K_VERSION=	0.1.1
T4K_DISTFILE=	${T4K_NAME}-${T4K_VERSION}${EXTRACT_SUFX}
T4K_WRKSRC=	${WRKDIR}/${T4K_NAME}-${T4K_VERSION}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSVG}
USE_GNOME+=	librsvg2
.else
CONFIGURE_ARGS+=--without-rsvg
.endif

# use multiple make jobs for T4K_WRKSRC
.if !defined(DISABLE_MAKE_JOBS)
_make_jobs=	-j${MAKE_JOBS_NUMBER}
.endif

post-extract:
	@${LN} -sf ${T4K_WRKSRC} ${WRKDIR}/${T4K_NAME}

post-patch:
.for file in convert_utf.h mysetenv.h practice.c
	@${ECHO_CMD} >> ${WRKSRC}/src/${file}
.endfor
	@${REINPLACE_CMD} -e \
		'/doc[[:space:]]/d' ${WRKSRC}/Makefile.in
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
	@(cd ${T4K_WRKSRC} && ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} \
		${MAKEFILE} ${_make_jobs} ${ALL_TARGET})

post-install:
	@${ECHO_CMD} -n > ${ETCDIR}/.keep_me
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for file in AUTHORS ChangeLog OFL README TODO
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.html ${DOCSDIR}/en
.endif

.include <bsd.port.mk>

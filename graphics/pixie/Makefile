# New ports collection makefile for:	pixie
# Date created:		29 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	pixie
PORTVERSION=	1.3.4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A photorealistic renderer with Pixar's RenderMan-like interface

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk_gl.1:${PORTSDIR}/x11-toolkits/fltk

USE_REINPLACE=	yes
USE_GL=		yes
USE_X_PREFIX=	yes
USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_AUTOHEADER_VER=	213
USE_LIBTOOL_VER=	13
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		CXXFLAGS="${CXXFLAGS} -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/Pixie

PIXIE_EXES=	precomp rndr sdrc sdrinfo show texmake
PIXIE_SHLIBS=	file framebuffer rgbe

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502112
BROKEN=		"Does not install on FreeBSD >= 5.x"
.endif

post-patch:
	@${REINPLACE_CMD} -i "" -e 's|malloc\.h|stdlib\.h|g' \
		`${FIND} -E ${WRKSRC} -iregex '.*\.(cpp|h)'`

do-install:
# exes
.for i in ${PIXIE_EXES}
	if [ "`${FILE} -b ${WRKSRC}/src/${i}/${i} | ${GREP} script`" ]; then \
	  ${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/.libs/${i} ${PREFIX}/bin; \
	else \
	  ${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/${i} ${PREFIX}/bin; \
	fi;
.endfor

# libs
	# avoid conflicts by installing in separate dir
	@${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/sdr/libsdr.a ${PREFIX}/lib/${PORTNAME}

	${INSTALL_DATA} ${WRKSRC}/src/ri/.libs/libri.a ${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/ri/.libs/libri.la ${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/ri/.libs/libri.so.0 ${PREFIX}/lib/${PORTNAME}
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/libri.so.0 ${PREFIX}/lib/${PORTNAME}/libri.so

.for i in ${PIXIE_SHLIBS}
	${INSTALL_DATA} ${WRKSRC}/src/${i}/.libs/${i}.a \
		${PREFIX}/lib/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/${i}/.libs/${i}.la \
		${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/.libs/${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}/${i}.so
.endfor

# includes
	@${MKDIR} ${PREFIX}/include/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/src/sdr/sdr.h ${PREFIX}/include/${PORTNAME}
.for i in dlo dsply implicit ri shadeop
	${INSTALL_DATA} ${WRKSRC}/src/ri/${i}.h ${PREFIX}/include/${PORTNAME}
.endfor

# shaders
	@${MKDIR} ${DATADIR}
	@${MKDIR} ${DATADIR}/shaders
	${INSTALL_DATA} ${WRKSRC}/shaders/* ${DATADIR}/shaders

# docs
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/figures
	${INSTALL_DATA} ${WRKSRC}/doc/figures/*.jpg ${DOCSDIR}/figures
.endif

post-install:
	@(${SED} -e 's|%%PREFIX%%|${PREFIX}|; s|%%PORTNAME%%|${PORTNAME}|' \
		<pkg-message >${PKGMESSAGE} && ${CAT} ${PKGMESSAGE})

.include <bsd.port.post.mk>

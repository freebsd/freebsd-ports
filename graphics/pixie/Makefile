# New ports collection makefile for:	pixie
# Date created:		29 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	pixie
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A photorealistic renderer with Pixar's RenderMan-like interface

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk_gl.1:${PORTSDIR}/x11-toolkits/fltk

USE_GL=		yes
USE_X_PREFIX=	yes
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_AUTOTOOLS=	autoconf:259 aclocal:19 automake:19 libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -O -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		CXXFLAGS="${CXXFLAGS} -O -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PORTNAME} --with-shaderdir=${PREFIX}/share/${PORTNAME}/shaders --with-modeldir=${PREFIX}/share/${PORTNAME} --with-texturedir=${PREFIX}/share/${PORTNAME} --with-proceduraldir=${PREFIX}/share/${PORTNAME} --with-displaysdir=${PREFIX}/lib/${PORTNAME}
USE_LDCONFIG=	%%PREFIX%%/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/Pixie

PIXIE_EXES=	precomp rndr sdrc sdrinfo show texmake
PIXIE_SHLIBS=	file framebuffer rgbe

SUB_LIST+=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

post-patch:
	@${FIND} -X ${WRKSRC} -name '*.cpp' -or -name '*.h' | \
		${XARGS} ${REINPLACE_CMD} -i '' -e 's|malloc\.h|stdlib\.h|g'

pre-configure:
	@${REINPLACE_CMD} -e '/^_LT_AC_SHELL_INIT/d' ${WRKSRC}/aclocal.m4

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
.for i in sdr ri common
	${INSTALL_DATA} ${WRKSRC}/src/${i}/.libs/lib${i}.a \
		${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/.libs/lib${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/lib${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}/lib${i}.so
.endfor

.for i in ${PIXIE_SHLIBS}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/.libs/${i}.so \
		${PREFIX}/lib/${PORTNAME}
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
	${INSTALL_DATA} ${WRKSRC}/doc/*.jpg ${DOCSDIR}
.for i in figures rayshadow running softshadow
	@${MKDIR} ${DOCSDIR}/${i}
	${INSTALL_DATA} ${WRKSRC}/doc/${i}/* ${DOCSDIR}/${i}
.endfor
.endif

.include <bsd.port.post.mk>

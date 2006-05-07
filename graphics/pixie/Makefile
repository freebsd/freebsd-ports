# New ports collection makefile for:	pixie
# Date created:		29 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	pixie
PORTVERSION=	1.5.5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ip@doom.homeunix.org
COMMENT=	A photorealistic renderer with Pixar's RenderMan-like interface

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk_gl.1:${PORTSDIR}/x11-toolkits/fltk

USE_GL=		yes
USE_X_PREFIX=	yes
USE_AUTOTOOLS=	automake:15:env autoconf:253 libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="${CFLAGS} -O -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		CXXFLAGS="${CXXFLAGS} -O -fPIC -I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib" \
		LIBS="${PTHREAD_LIBS}"
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/Pixie

PIXIE_EXES=	precomp rndr sdrc sdrinfo show texmake
PIXIE_SHLIBS=	file framebuffer rgbe

SUB_FILES=	pkg-message
SUB_LIST+=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
NOT_FOR_ARCHS=	alpha
.endif

.if ${OSVERSION} >= 600000 && ${ARCH} == "sparc64"
BROKEN=	"doesn't compile because of internal gcc failure"
.endif

post-patch:
	@${FIND} -X ${WRKSRC} -name '*.cpp' -or -name '*.h' | \
		${XARGS} ${REINPLACE_CMD} -i '' -e 's|malloc\.h|stdlib\.h|g'


pre-configure:
	@(cd ${WRKSRC} && ${ACLOCAL} && \
	${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} --add-missing && \
	${SETENV} ${AUTOTOOLS_ENV} ${AUTOMAKE} -i)
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
.for i in sdr ri
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

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

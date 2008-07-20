# New ports collection makefile for:	pixie
# Date created:		29 Jan 2004
# Whom:			Igor Pokrovsky <tiamat@comset.net>
#
# $FreeBSD$
#

PORTNAME=	pixie
PORTVERSION=	2.2.3
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	Pixie-src-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	beech@FreeBSD.org
COMMENT=	A photorealistic renderer with Pixar's RenderMan-like interface

BUILD_DEPENDS=	flex:${PORTSDIR}/textproc/flex \
		bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		fltk_gl.1:${PORTSDIR}/x11-toolkits/fltk \
		IlmImf.6:${PORTSDIR}/graphics/OpenEXR

NOT_FOR_ARCHS=	amd64

PORTDOCS=*
USE_GL=		yes
ACLOCAL_ARGS=	--acdir=${ACLOCAL_DIR} -I ${LOCALBASE}/share/aclocal
USE_AUTOTOOLS=	autoconf:261 aclocal:19 automake:19 libtool:15
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CFLAGS="-O0 -fPIC -pipe -I${LOCALBASE}/include" \
		CXXFLAGS="-O0 -pipe -fPIC -I${LOCALBASE}/include \
			-I${LOCALBASE}/include/OpenEXR" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--with-docdir=${PREFIX}/share/doc/${PORTNAME} \
	--with-shaderdir=${PREFIX}/share/${PORTNAME}/shaders \
	--with-modeldir=${PREFIX}/share/${PORTNAME} \
	--with-texturedir=${PREFIX}/share/${PORTNAME} \
	--with-proceduraldir=${PREFIX}/share/${PORTNAME} \
	--with-displaysdir=${PREFIX}/lib/${PORTNAME} \
	--with-openexr=${LOCALBASE}/lib \
	--enable-openexr-threads --disable-openexrtest

USE_LDCONFIG=	${LOCALBASE}/lib/${PORTNAME}
WRKSRC=		${WRKDIR}/Pixie

PIXIE_EXES=	precomp rndr sdrc sdrinfo show texmake
PIXIE_SHLIBS=	file framebuffer rgbe

SUB_LIST+=	PORTNAME=${PORTNAME}

.include <bsd.port.pre.mk>

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
	@${INSTALL} -d ${PREFIX}/lib/${PORTNAME}
.for i in common
	${INSTALL_DATA} ${WRKSRC}/src/${i}/.libs/libpixie${i}.a \
		${PREFIX}/lib/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/src/${i}/.libs/libpixie${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}
	${LN} -sf ${PREFIX}/lib/${PORTNAME}/libpixie${i}.so.0 \
		${PREFIX}/lib/${PORTNAME}/libpixie${i}.so
.endfor
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
	@${INSTALL} -d ${PREFIX}/include/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/src/sdr/sdr.h ${PREFIX}/include/${PORTNAME}
.for i in dlo dsply implicit ri shadeop
	${INSTALL_DATA} ${WRKSRC}/src/ri/${i}.h ${PREFIX}/include/${PORTNAME}
.endfor

# shaders
	@${INSTALL} -d ${DATADIR}
	@${INSTALL} -d ${DATADIR}/shaders
	@${INSTALL_DATA} ${WRKSRC}/shaders/* ${DATADIR}/shaders

# docs
.ifndef (NOPORTDOCS)
	@cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

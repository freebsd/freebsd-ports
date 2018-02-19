# Created by: ijliao
# $FreeBSD$

PORTNAME=	gsculpt
PORTVERSION=	0.99.47
PORTREVISION=	17
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME:S,-src,,}
DISTNAME=	gSculpt-${PORTVERSION}-alpha-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Opensource 3D modelling application

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	${PY_BOOST}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}PyOpenGL>0:graphics/py-PyOpenGL@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gtkglext>0:x11-toolkits/py-gtkglext@${PY_FLAVOR}

BROKEN_aarch64=		fails to compile: cpp/extlibs/greenlet/greenlet.c:254:2: greenlet needs to be ported to this platform
BROKEN_powerpc=		fails to compile
BROKEN_sparc64=		fails to compile

WRKSRC=		${WRKDIR}/${DISTNAME:S,-src,,}

USES=		pkgconfig python:2.7 scons
USE_GNOME=	pygtk2
USE_GL=		glu
USE_XORG=	x11
USE_LDCONFIG=	${PREFIX}/lib/gSculpt

DATADIR=	${PREFIX}/share/gSculpt

DESKTOP_ENTRIES="gSculpt" "" \
		"${DATADIR}/gsimages/gSculpt_Glass_Master_by_Gary_Rose.png" \
		"${PORTNAME}" "Graphics;GTK;" ""

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
CFLAGS+=	-DGSCULPT_FPU_X86
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"s| gsculpt.py| ${PYTHONPREFIX_SITELIBDIR}/gSculpt/gsculpt.py|" \
		${WRKSRC}/gsculpt
	@${REINPLACE_CMD} -e \
		"s|'-Werror'|''| ; \
		 s|'-g'|''| ; \
		 s|'-DGSCULPT_FPU_X86'|''| ; \
		 s|'[(]-O2.*-O[)]'|''| ; \
		 /^cppLibs/s|BackgroundModel|BackgroundMesh|" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e \
		"/^prefix/s|=.*|= '${STAGEDIR}${PREFIX}'| ; \
		 /^gSculptStartDir/s|=.*|= os.path.join( pysitelibdir )|" \
		${WRKSRC}/SConstruct-install
	@${REINPLACE_CMD} -e \
		"s|#GSCULPT_LIBRARY_PATH#|${LOCALBASE}/lib/gSculpt|; \
		 s|python|${PYTHON_CMD}|; \
		 s|#GSCULPT_START#|${PYTHONPREFIX_SITELIBDIR}/gsculpt.py|" \
		${WRKSRC}/posixbuild/gsculpt

do-install:
	@(cd ${WRKSRC} && ${SCONS} -f SConstruct-install install)
	@(cd ${STAGEDIR}${PREFIX} && ${PYTHON_CMD} -m compileall \
		-d ${PREFIX} -f ${PYTHONPREFIX_SITELIBDIR:S;${PREFIX}/;;})
	@${FIND} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/Britefury \
		-name "*.so" -exec ${STRIP_CMD} {} \;
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/gSculpt/*.so

.include <bsd.port.post.mk>

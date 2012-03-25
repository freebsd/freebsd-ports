# New ports collection makefile for:	gSculpt
# Date created:			Oct 10, 2001
# Whom:				ijliao
#
# $Carpetsmoker: ports/graphics/gsculpt/Makefile,v 1.4 2007/08/02 13:13:45 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	gsculpt
PORTVERSION=	0.99.47
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTNAME:S,-src,,}
DISTNAME=	gSculpt-${PORTVERSION}-alpha-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Opensource 3D modelling application

LICENSE=	GPLv2

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opengl>0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}gtkglext>0:${PORTSDIR}/x11-toolkits/py-gtkglext

WRKSRC=		${WRKDIR}/${DISTNAME:S,-src,,}

USE_GNOME=	pygtk2
USE_GL=		glu
USE_XORG=	x11
USE_PYTHON=	2.4+
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
USE_LDCONFIG=	${PREFIX}/lib/gSculpt
MAKE_JOBS_SAFE=	yes

DATADIR=	${PREFIX}/share/gSculpt

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.if ${ARCH} == "i386"
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
		"/^prefix/s|=.*|= '${PREFIX}'| ; \
		 /^gSculptStartDir/s|=.*|= os.path.join( pysitelibdir )|" \
		${WRKSRC}/SConstruct-install

do-install:
	@cd ${WRKSRC} && ${SCONS_BIN} -f SConstruct-install ${PREFIX}

.include <bsd.port.post.mk>

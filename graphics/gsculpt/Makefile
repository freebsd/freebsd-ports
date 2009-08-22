# New ports collection makefile for:	gSculpt
# Date created:			Oct 10, 2001
# Whom:				ijliao
#
# $Carpetsmoker: ports/graphics/gsculpt/Makefile,v 1.4 2007/08/02 13:13:45 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	gsculpt
PORTVERSION=	0.99.46.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/gSculpt-${PORTVERSION}-alpha
DISTNAME=	gSculpt-${PORTVERSION}-alpha-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An Opensource 3D modelling application

LIB_DEPENDS=	boost_python:${PORTSDIR}/devel/boost-python-libs
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gtkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

WRKSRC=		${WRKDIR}/gSculpt-${PORTVERSION}-alpha
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
USE_PYTHON=	2.4+
USE_XORG=	x11
USE_GL=		yes
USE_GNOME=	pygtk2
USE_LDCONFIG=	${PREFIX}/lib/gSculpt
DATADIR=	${PREFIX}/share/gSculpt

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|gsculpt.py|${PYTHONPREFIX_SITELIBDIR}/gSculpt/gsculpt.py|" \
		${WRKSRC}/gsculpt
	@${REINPLACE_CMD} -e "s|prefix = os.path.join( '/usr', 'local' )|prefix='${PREFIX}'|; \
		s|'bin', 'gSculpt'|'${PYTHONPREFIX_SITELIBDIR}'|;" \
		${WRKSRC}/SConstruct-install
	@${REINPLACE_CMD} -e "s|-O2|-O1\|-O2|;" \
		${WRKSRC}/SConstruct
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -e "s|, '-DGSCULPT_FPU_X86'||;" \
		${WRKSRC}/SConstruct
.endif

do-install:
	@cd ${WRKSRC} && \
	${SCONS_BIN} -f SConstruct-install ${PREFIX}

.include <bsd.port.post.mk>

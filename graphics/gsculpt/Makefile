# New ports collection makefile for:	gSculpt
# Date created:			Oct 10, 2001
# Whom:				ijliao
#
# $Carpetsmoker: ports/gsculpt/Makefile,v 1.3 2007/04/22 12:24:12 carpetsmoker Exp $
# $FreeBSD$
#

PORTNAME=	gsculpt
PORTVERSION=	0.99.39.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	gSculpt-${PORTVERSION}-alpha-src

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	An Opensource 3D modelling application

LIB_DEPENDS=	boost_python.4:${PORTSDIR}/devel/boost-python
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/gtkgl/__init__.py:${PORTSDIR}/x11-toolkits/py-gtkglext \
		${PYTHON_SITELIBDIR}/OpenGL/__init__.py:${PORTSDIR}/graphics/py-opengl

SUB_FILES=	SConstruct-install
SUB_LIST=	PYTHONPREFIX_SITELIBDIR=${PYTHONPREFIX_SITELIBDIR} \
		WRKSRC=${WRKSRC}

WRKSRC=		${WRKDIR}/gSculpt-${PORTVERSION}-alpha
USE_DOS2UNIX=	SConstruct
USE_SCONS=	yes
SCONS_BUILDENV=	${SCONS_ENV}
USE_PYTHON=	2.4
USE_XLIB=	yes
USE_GL=		yes
USE_GNOME=	pygtk2
USE_LDCONFIG=	${PREFIX}/lib/gSculpt

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/include/python2.4|${LOCALBASE}/include/python2.4|" \
		${WRKSRC}/SConstruct
	@${REINPLACE_CMD} -e "s|gsculpt.py|${PYTHONPREFIX_SITELIBDIR}/gSculpt/gsculpt.py|" \
		${WRKSRC}/gsculpt
do-install:
	@cd ${WRKDIR} && \
	${SCONS_BIN} -f SConstruct-install ${PREFIX} ${PYTHONPREFIX_SITELIBDIR}

.include <bsd.port.post.mk>

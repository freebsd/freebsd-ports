# New ports collection makefile for:	libaux
# Date created:				14 March 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libaux
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/
DISTFILES=	libaux${EXTRACT_SUFX} libtk${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Nano Window Toolkit and Auxiliary Library for OpenGL

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=		glut
USE_IMAKE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libaux.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/aux.h ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/../libtk/tk.h ${PREFIX}/include/GL

.include <bsd.port.mk>

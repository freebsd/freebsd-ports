# New ports collection makefile for:	libaux
# Date created:				14 March 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libaux
PORTVERSION=	1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.rus.uni-stuttgart.de/pub/systems/sgi/OpenGL/contrib/
DISTFILES=	libaux${EXTRACT_SUFX} libtk${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Nano Window Toolkit and Auxiliary Library for OpenGL

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_IMAKE=	yes
USE_MESA=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libaux.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/aux.h ${PREFIX}/include/GL
	${INSTALL_DATA} ${WRKSRC}/../libtk/tk.h ${PREFIX}/include/GL

.include <bsd.port.mk>

# New ports collection makefile for:	gltk
# Date created:		16 Feb 2000
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	gltk
PORTVERSION=	1.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sgi.com/opengl/contrib/ \
		ftp://ftp.u-aizu.ac.jp/pub/os/sgi/misc/ftp.sgi.com/pub/opengl/contrib/
DISTNAME=	libtk
EXTRACT_SUFX=	.tar.Z

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL/Tk interface

USE_GL=		glut
USE_IMAKE=	yes
USE_XORG=	x11

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtk.a ${PREFIX}/lib/libgltk.a
	${INSTALL_DATA} ${WRKSRC}/tk.h ${PREFIX}/include/GL/gltk.h
	${MKDIR} ${PREFIX}/share/doc/gltk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gltk

.include <bsd.port.mk>

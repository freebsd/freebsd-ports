# New ports collection makefile for:	gltk
# Version required:	1.0
# Date created:		16 Feb 2000
# Whom:			asami
#
# $FreeBSD$
#

DISTNAME=	libtk
PKGNAME=	gltk-1.0
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.sgi.com/opengl/contrib/ \
		ftp://ftp.u-aizu.ac.jp/pub/os/sgi/misc/ftp.sgi.com/pub/opengl/contrib/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	GL.14:${PORTSDIR}/graphics/Mesa3

USE_IMAKE=	yes

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtk.a ${PREFIX}/lib/libgltk.a
	${INSTALL_DATA} ${WRKSRC}/tk.h ${PREFIX}/include/GL/gltk.h
	${MKDIR} ${PREFIX}/share/doc/gltk
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/gltk

.include <bsd.port.mk>

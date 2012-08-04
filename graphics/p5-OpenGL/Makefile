# ex:ts=8
# Ports collection makefile for:	p5-OpenGL
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	OpenGL
PORTVERSION=	0.66
PORTREVISION=	1
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to display 3D data using OpenGL, GLU, GLUT, and GLX

CONFIGURE_ARGS=	interface=GLUT
PERL_CONFIGURE=	yes
USE_DISPLAY=	yes
USE_GL=		glut

MAN3=		Array.3 \
		OpenGL.3 \
		Tessellation.3

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

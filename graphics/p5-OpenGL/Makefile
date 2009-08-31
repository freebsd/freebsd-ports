# ex:ts=8
# Ports collection makefile for:	p5-OpenGL
# Date created:			Jan 7, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	OpenGL
PORTVERSION=	0.54
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/I/IL/ILYAZ/modules
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module to display 3D data using OpenGL, GLU, GLUT, and GLX

USE_GL=		glut
PERL_CONFIGURE=	yes

post-patch:
	@${PERL} -pi -e "s|%%PTHREAD_LIBS%%|${PTHREAD_LIBS}|g; s|/usr/X11R6|${LOCALBASE}|g" ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

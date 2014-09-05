# Created by: ijliao
# $FreeBSD$

PORTNAME=	OpenGL
PORTVERSION=	0.66
PORTREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to display 3D data using OpenGL, GLU, GLUT, and GLX

MANUAL_PACKAGE_BUILD=	fails to start X server on pointyhat

CONFIGURE_ARGS=	interface=FREEGLUT
USES=		perl5 display:configure
USE_PERL5=	configure
USE_GL=		glut

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

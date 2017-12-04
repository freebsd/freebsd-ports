# Created by: ijliao
# $FreeBSD$

PORTNAME=	OpenGL
PORTVERSION=	0.66
PORTREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CHM
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl module to display 3D data using OpenGL, GLU, GLUT, and GLX

BUILD_DEPENDS=	${PREFIX}/bin/Xvfb:x11-servers/xorg-vfbserver \
	${PREFIX}/bin/xauth:x11/xauth \
	${PREFIX}/bin/getopt:misc/getopt

PORTSCOUT=	limit:^[0-9\.]*$$

CONFIGURE_ARGS=	interface=FREEGLUT
CONFIGURE_ENV+= TERM=xterm
USES=		perl5 display:configure
USE_PERL5=	configure
USE_GL=		glut
USE_XORG=	x11 xext xmu xi ice

# TODO create xvfb-run port
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/Makefile.PL

pre-configure:
	${CP} ${FILESDIR}/xvfb-run ${WRKSRC}/
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|g' \
		${WRKSRC}/xvfb-run

do-configure:
	cd ${CONFIGURE_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} \
		${SH} ./xvfb-run -a -s "+extension GLX -screen 0 1280x1024x24" \
		${PERL5} ${CONFIGURE_CMD} ${CONFIGURE_ARGS}

.include <bsd.port.mk>

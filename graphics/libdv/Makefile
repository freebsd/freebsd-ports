# New ports collection makefile for:	libdv
# Date created:				Sun Nov 18 19:42:02 BRST 2001
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libdv
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		popt.0:${PORTSDIR}/devel/popt

USE_GNOMELIBS=	yes
USE_XLIB=	yes
XFREE86_VERSION=	4
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

MAN1=	encodedv.1 playdv.1

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

DOC_FILES=	ChangeLog README.dvconnect README.encoder

.ifndef(WITHOUT_SDL)
LIB_DEPENDS+=	SDL-1.1.3:${PORTSDIR}/devel/sdl12

CONFIGURE_ARGS+= --enable-sdl
CONFIGURE_ENV+=	SDL_CONFIG="${SDL_CONFIG}"
.endif

pre-everything::
	@${ECHO_MSG} '===>'
	@${ECHO_MSG} '===>           ATTENTION          <==='
	@${ECHO_MSG} '===> YOU NEED XFREE86 Version 4.0 <==='
	@${ECHO_MSG} '===> or above to run this         <==='
	@${ECHO_MSG} '===> SINCE IT REQUIRES XV         <==='
	@${ECHO_MSG} '===>'
.ifndef(WITHOUT_SDL)
	@${ECHO_MSG} '===> Define WITHOUT_SDL to disable SDL support'
.endif
	@${ECHO_MSG} '===>'

post-configure:
	@find ${WRKSRC} -type f -name Makefile -exec \
		${PERL} -pi.orig -ne 's!-l(gdk|glib|gtk) !!g' {} \;

post-install:
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

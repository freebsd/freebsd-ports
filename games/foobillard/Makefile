# New ports collection makefile for:	foobillard
# Date created:				26 October 2002
# Whom:					Thomas Vogt <thomas.vogt@bsdunix.ch>
#
# $FreeBSD$
#

PORTNAME=	foobillard
PORTVERSION=	2.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://foobillard.sunsite.dk/dnl/

MAINTAINER=	thomas.vogt@bsdunix.ch
COMMENT=	A free OpenGL-billard game

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		freetype.9:${PORTSDIR}/print/freetype2

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"does not compile on sparc64"
.endif

FREETYPE_CONFIG?=	${LOCALBASE}/bin/freetype-config

USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes

CPPFLAGS=	-I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib"

.if defined(WITH_SDL)
USE_SDL=	yes
CONFIGURE_ARGS+=	--enable-SDL
.else
LIB_DEPENDS+=	glut.3:${PORTSDIR}/graphics/libglut
CONFIGURE_ARGS+=	--enable-glut
.endif

.if !defined(WITH_NVIDIA_BUMPREF)
CONFIGURE_ARGS+=	--disable-nvidia
.endif

MAN6=		foobillard.6

pre-everything::
.if !defined(WITH_SDL) || !defined(WITH_NVIDIA_BUMPREF)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} ""
.endif

.if !defined(WITH_SDL)
	@${ECHO_MSG} "WITH_SDL=yes to use SDL-lib instead of glut"
.endif

.if !defined(WITH_NVIDIA_BUMPREF)
	@${ECHO_MSG} "WITH_NVIDIA_BUMPREF=yes to enable NV-extensions"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%FREETYPE_CONFIG%%|${FREETYPE_CONFIG}|g' \
		${WRKSRC}/src/Makefile.in

post-install:
	@${INSTALL_MAN} ${WRKSRC}/foobillard.6 ${PREFIX}/man/man6/foobillard.6

.include <bsd.port.post.mk>

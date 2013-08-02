# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	white_dune
PORTVERSION=	${DISTVERSION:S/pl/./}
DISTVERSION=	0.30pl5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://vrml.cip.ica.uni-stuttgart.de/dune/

MAINTAINER=	devel@stasyan.com
COMMENT=	Graphical VRML97 editor and animation tool

LIB_DEPENDS=	libjpeg.so:${PORTSDIR}/graphics/jpeg \
		libpng15.so:${PORTSDIR}/graphics/png

LICENSE=	GPLv2

USES=		motif
USE_XORG=	xft
USE_GL=		gl glu glut
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	YACC="/usr/bin/byacc"
CONFIGURE_ARGS=	--with-optimization \
		--without-devil \
		--with-helpurl="${DOCSDIR}/index.html" \
		--with-vrml97am1url="${DOCSDIR}/vrml97Amendment1" \
		--with-x3ddrafturl="${DOCSDIR}/x3dDraft" \
		--with-scriptednodesurl="${DOCSDIR}/scriptedNodes"
CPPFLAGS+=	`${SDL_CONFIG} --cflags` -DUSBHID_UCR_DATA -DUSBHID_NEW \
		-D__FREEBSD__
LDFLAGS+=	`${SDL_CONFIG} --libs`
ALL_TARGET=	dune
REINPLACE_ARGS=	-i ''

MAN1=		dune.1 illegal2vrml.1

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

# Try to fix parallel builds (-jX) by calling submakes correctly
post-patch:
	@${FIND} ${WRKSRC} -name Makefile\* | ${XARGS} ${REINPLACE_CMD} -E \
		's,cd (.+) *(;|&&) *(make|\$$\(MAKE\)),$$(MAKE) -C \1,'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${PREFIX}/bin
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} dune4kids illegal2vrml \
		${PREFIX}/bin
	cd ${WRKSRC}/man && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif

.include <bsd.port.mk>

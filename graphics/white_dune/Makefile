# ex:ts=8
# Ports collection makefile for:	white_dune
# Date created:			Apr 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	white_dune
PORTVERSION=	0.28.11
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.csv.ica.uni-stuttgart.de/vrml/dune/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}pl${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical VRML97 Editor and animation tool

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		glut.3:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_MOTIF=	yes
USE_GL=		yes
USE_SDL=	sdl
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		YACC="/usr/bin/byacc"
CONFIGURE_ARGS=	--with-optimization \
		--without-devil \
		--with-helpurl="${DOCSDIR}/index.html" \
		--with-vrml97am1url="${DOCSDIR}/vrml97Amendment1" \
		--with-x3ddrafturl="${DOCSDIR}/x3dDraft" \
		--with-scriptednodesurl="${DOCSDIR}/scriptedNodes"
ALL_TARGET=	# empty

MAN1=		dune.1 illegal2vrml.1

CPPFLAGS=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` \
		-DUSBHID_UCR_DATA
LDFLAGS=	-L${LOCALBASE}/lib `${SDL_CONFIG} --libs`

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500111
CPPFLAGS+=	-DUSBHID_NEW
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${PREFIX}/bin
.for file in dune4kids illegal2vrml
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${file} ${PREFIX}/bin
.endfor
.for file in dune.1 illegal2vrml.1
	${INSTALL_MAN} ${WRKSRC}/man/${file} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		${CPIO} -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

# ex:ts=8
# Ports collection makefile for:	white_dune
# Date created:			Apr 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	white_dune
PORTVERSION=	0.26.1
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.csv.ica.uni-stuttgart.de/vrml/dune/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}pl${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphical VRML97 Editor and animation tool

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		glut:${PORTSDIR}/graphics/libglut \
		png.5:${PORTSDIR}/graphics/png

USE_MOTIF=	yes
USE_GL=		yes
USE_SDL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		YACC="/usr/bin/byacc"
CONFIGURE_ARGS=	--with-optimization \
		--without-devil \
		--with-helpurl="${DOCSDIR}/index.html" \
		--with-nurbscurveprotourl="${DATADIR}/NurbsCurvePROTO.wrl" \
		--with-nurbsgroupprotourl="${DATADIR}/NurbsGroupPROTO.wrl" \
		--with-nurbssurfaceprotourl="${DATADIR}/NurbsSurfacePROTO.wrl"
ALL_TARGET=	# empty

MAN1=		dune.1

CPPFLAGS=	-I${LOCALBASE}/include `${SDL_CONFIG} --cflags` \
		-DUSBHID_UCR_DATA
LDFLAGS=	-L${LOCALBASE}/lib `${SDL_CONFIG} --libs`

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500111
CPPFLAGS+=	-DUSBHID_NEW
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bin/dune4kids ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/dune.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DATADIR}
.for file in NurbsCurvePROTO.wrl NurbsGroupPROTO.wrl NurbsSurfacePROTO.wrl
	${INSTALL_DATA} ${WRKSRC}/docs/vrml200x_nurbssurface/${file} ${DATADIR}
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/docs && ${FIND} . | \
		cpio -pdm -L -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

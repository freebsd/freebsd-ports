# New ports collection makefile for:	tuxracer
# Date created:				8 August 2000
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	tuxracer
PORTVERSION=	0.12.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=tuxracer
DISTFILES=	${PORTNAME}-${PORTVERSION}.tar.gz \
		${PORTNAME}-data-${PORTVERSION}.tar.gz

MAINTAINER=	anholt@teleport.com

LIB_DEPENDS=	glut.3:${PORTSDIR}/graphics/Mesa3 \
		tcl82.1:${PORTSDIR}/lang/tcl82

USE_X_PREFIX=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl-inc="${LOCALBASE}/include/tcl8.2" \
		--with-tcl-libs="${LOCALBASE}/lib" \
		--with-tcl-lib-name=tcl82 \
		--with-glut-libs="${X11BASE}/lib" \
		--with-glut-inc="${X11BASE}/include" \
		--with-data-dir=${PREFIX}/share/tuxracer

CFLAGS+=	-L${X11BASE}/lib

WORKDATA=	${WRKDIR}/${PORTNAME}-data-${PORTVERSION}
SHAREDIR=	${PREFIX}/share/${PORTNAME}
COURSEDIRS=	1 2 3 4 5 6 7 8 9 10 11

post-install:
	${MKDIR} ${SHAREDIR}/courses
.for i in ${COURSEDIRS}
		${MKDIR} ${SHAREDIR}/courses/${i}
		${INSTALL_DATA} ${WORKDATA}/courses/${i}/course.tcl ${SHAREDIR}/courses/${i}/
		${INSTALL_DATA} ${WORKDATA}/courses/${i}/elev.rgb ${SHAREDIR}/courses/${i}/
		${INSTALL_DATA} ${WORKDATA}/courses/${i}/terrain.rgb ${SHAREDIR}/courses/${i}/
		${INSTALL_DATA} ${WORKDATA}/courses/${i}/trees.rgb ${SHAREDIR}/courses/${i}/
.endfor
	${MKDIR} ${SHAREDIR}/courses/common
	${INSTALL_DATA} ${WORKDATA}/courses/common/background1.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/background2.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/background3.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/ice.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/rock.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/snow.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/standard_light.tcl ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/tree.rgb ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/tree_polyhedron.tcl ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/tux_moonwalk.tcl ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/courses/common/tux_walk.tcl ${SHAREDIR}/courses/common/
	${INSTALL_DATA} ${WORKDATA}/tux.tcl ${SHAREDIR}/

.include <bsd.port.mk>

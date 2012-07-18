# New Ports collection makefile for:	Asteroids3D
# Date created:		2012-05-20
# Whom:			nemysis@gmx.ch
#
# $FreeBSD$
#

PORTNAME=	asteroids3d
PORTVERSION=	0.5.1
CATEGORIES=	games
MASTER_SITES=	SF/a3d/${PORTVERSION}/ \
		LOCAL/madpilot/asteroids3d/:icons
DISTNAME=	${PORTNAME:S/3d/3D/}-${DISTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		asteroids3d_icons.tbz:icons

MAINTAINER=	nemysis@gmx.ch
COMMENT=	First-person shooter blowing up asteroids in 3D space

LICENSE=	GPLv2

WRKSRC=		${WRKDIR}/${PORTNAME:S/3d/3D/}-${PORTVERSION}

USE_BZIP2=	yes
USE_AUTOTOOLS=	aclocal autoheader
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	with_gamesdir="${PREFIX}/bin" with_gamedatadir="${DATADIR}"
USE_GL=		glut glu
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}_128.png \
		share/pixmaps/${PORTNAME}_48.png

PORTDATA=	*
PORTDOCS=	README.html

pre-configure:
	@(cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ./autogen.sh)

post-patch:
	@${REINPLACE_CMD} -e 's|/bin/bash|/bin/sh|g' ${WRKSRC}/autogen.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME:S/3d/3D/} ${PREFIX}/bin/${PORTNAME}
# Pixmaps
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}*.png ${PREFIX}/share/pixmaps
# Data
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	@(cd ${WRKSRC}/src && ${COPYTREE_SHARE}  "*.ub *.ppm" ${DATADIR})
.endif
# Documentation
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	tuxracer
# Date created:				8 August 2000
# Whom:					Eric Anholt
#
# $FreeBSD$
#

PORTNAME=	tuxracer
PORTVERSION=	0.61
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}-data/${PORTVERSION}:data
DISTFILES=	${PORTNAME}-${PORTVERSION}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D penguin racing game using OpenGL

USE_SDL=	mixer sdl
USE_GL=		gl
USE_XORG=	x11 xt xmu xi
USE_TK_BUILD=	yes
USE_TK=		yes
USE_GMAKE=	yes
USE_AUTOTOOLS=	automake14 autoconf
AUTOMAKE_ARGS=	-a
CONFIGURE_ENV=	THREAD_LIB="${PTHREAD_LIBS}"
CONFIGURE_ARGS=	--with-tcl-inc="${TCL_INCLUDEDIR}" \
		--with-tcl-libs="${LOCALBASE}/lib" \
		--with-gl-libs="${LOCALBASE}/lib" \
		--with-gl-inc="${LOCALBASE}/include" \
		--with-data-dir=${DATADIR}
MAKE_ENV=	${CONFIGURE_ENV}

post-extract:
	@${RM} ${WRKSRC}/missing

post-install:
	@${MKDIR} ${DATADIR}
	@(cd ${WORKDATA} ${WRKDIR}/${PORTNAME}-data-${PORTVERSION} \
		&& ${COPYTREE_SHARE} . ${DATADIR})

.include <bsd.port.mk>

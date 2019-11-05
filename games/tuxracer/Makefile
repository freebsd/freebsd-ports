# Created by: Eric Anholt
# $FreeBSD$

PORTNAME=	tuxracer
PORTVERSION=	0.61
PORTREVISION=	14
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}-data/${PORTVERSION}:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D penguin racing game using OpenGL

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake sdl tk xorg
USE_SDL=	mixer sdl
USE_GL=		gl
USE_XORG=	x11 xt xmu xi
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-inc="${TCL_INCLUDEDIR}" \
		--with-tcl-libs="${LOCALBASE}/lib" \
		--with-tcl-lib-name=tcl${TCL_VER:S/.//} \
		--with-gl-libs="${LOCALBASE}/lib" \
		--with-gl-inc="${LOCALBASE}/include" \
		--with-data-dir=${DATADIR}
CPPFLAGS+=	-DGLX_GLXEXT_LEGACY

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WORKDATA} ${WRKDIR}/${PORTNAME}-data-${PORTVERSION} \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

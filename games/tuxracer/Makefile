PORTNAME=	tuxracer
PORTVERSION=	0.61
PORTREVISION=	15
CATEGORIES=	games
MASTER_SITES=	SF \
		SF/${PORTNAME}/${PORTNAME}-data/${PORTVERSION}:data
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-data-${PORTVERSION}${EXTRACT_SUFX}:data

MAINTAINER=	ports@FreeBSD.org
COMMENT=	3D penguin racing game using OpenGL
WWW=		https://tuxracer.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gl gmake sdl tk xorg
USE_GL=		gl glu
USE_SDL=	mixer sdl
USE_XORG=	ice sm x11 xext xi xmu xt

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-tcl-inc="${TCL_INCLUDEDIR}" \
		--with-tcl-libs="${LOCALBASE}/lib" \
		--with-tcl-lib-name=tcl${TCL_VER:S/.//} \
		--with-gl-libs="${LOCALBASE}/lib" \
		--with-gl-inc="${LOCALBASE}/include" \
		--with-data-dir=${DATADIR}

CPPFLAGS+=	-DGLX_GLXEXT_LEGACY

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WORKDATA} ${WRKDIR}/${PORTNAME}-data-${PORTVERSION} \
		&& ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	5.0.2
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	databases
MASTER_SITES=	http://grass.itc.it/grass5/source/ \
		ftp://grass.baylor.edu/pub/grass/grass5/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Geographical Information System (GIS)

POSTGRESQL_PORT?=	databases/postgresql7
LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gd.4:${PORTSDIR}/graphics/gd \
		fftw.2:${PORTSDIR}/math/fftw \
		iconv.3:${PORTSDIR}/converters/libiconv \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		pq.3:${PORTSDIR}/${POSTGRESQL_PORT} \
		odbc.1:${PORTSDIR}/databases/unixODBC \
		lapack.3:${PORTSDIR}/math/lapack
BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude *CVS*

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

USE_XLIB=	yes
USE_MESA=	yes
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
CONFIGURE_ARGS=	--with-includes=${LOCALBASE}/include \
		--with-libs=${LOCALBASE}/lib \
		--with-tcltk-includes="${LOCALBASE}/include/tcl8.3 \
					 ${LOCALBASE}/include/tk8.3" \
		--with-postgres-includes=${LOCALBASE}/include/postgresql/internal/ \
		--with-opengl-includes=${X11BASE}/include \
		--with-opengl-libs=${X11BASE}/lib \
		--with-freetype \
		--with-freetype-includes=${LOCALBASE}/include/freetype2 \
		--with-blas \
		--with-lapack \
		--with-nls \
		--without-motif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

post-install:
	-(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
	  ${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.post.mk>

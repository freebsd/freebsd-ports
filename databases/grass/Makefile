# New ports collection makefile for:	grass
# Date created:		15 January 2000
# Whom:			reg
#
# $FreeBSD$
#

PORTNAME=	grass
PORTVERSION=	5.0.2
PORTREVISION=	4
PORTEPOCH=	2
CATEGORIES=	databases
MASTER_SITES=	http://grass.itc.it/grass50/source/ \
		http://grass.meteo.uni.wroc.pl/grass50/source/ \
		ftp://sunsite.ualberta.ca/pub/Mirror/grass-web/grass50/source/ \
		http://www.dinama.gub.uy/grass/grass50/source/
DISTNAME=	${PORTNAME}-${PORTVERSION}_src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source Geographical Information System (GIS)

LIB_DEPENDS=	tiff.4:${PORTSDIR}/graphics/tiff \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		gd.4:${PORTSDIR}/graphics/gd \
		fftw.2:${PORTSDIR}/math/fftw \
		freetype.9:${PORTSDIR}/print/freetype2 \
		gdbm.3:${PORTSDIR}/databases/gdbm \
		odbc.1:${PORTSDIR}/databases/unixODBC \
		lapack.3:${PORTSDIR}/math/lapack
BUILD_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83
RUN_DEPENDS=	tclsh8.3:${PORTSDIR}/lang/tcl83 \
		wish8.3:${PORTSDIR}/x11-toolkits/tk83

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude *CVS*

WRKSRC=		${WRKDIR}/${PORTNAME}${PORTVERSION}

USE_PGSQL=	yes
USE_ICONV=	yes
USE_XLIB=	yes
USE_GL=		yes
USE_PERL5=	yes
USE_BISON=	yes
USE_GMAKE=	yes
USE_AUTOCONF_VER=	213
USE_REINPLACE=	yes
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

post-patch:
	@${REINPLACE_CMD} -e 's,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},' \
		-e 's,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},' ${WRKSRC}/configure.in

.include <bsd.port.pre.mk>

post-install:
	-(cd ${PREFIX} && ${GREP} -v "@" ${PLIST} | \
	  ${XARGS} ${STRIP_CMD} 2> /dev/null || ${TRUE})

.include <bsd.port.post.mk>

# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
PORTVERSION=	3.6.1
PORTREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.mirrorservice.org/sites/ftp.povray.org/pub/povray/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/povray/%SUBDIR%,}
MASTER_SITE_SUBDIR=	Official/Unix
DIST_SUBDIR=	povray36

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Persistence of Vision Ray Tracer

.if defined(WITH_ICC)
BUILD_DEPENDS=	${LOCALBASE}/intel_cc_80/bin/icc:${PORTSDIR}/lang/icc
.endif
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg

USE_XORG=	x11
USE_BZIP2=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	autoconf:262
LATEST_LINK=	${PORTNAME}36

.include <bsd.port.pre.mk>

.if (${ARCH} == "i386")
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
.endif

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.if (${ARCH} == "i386" && !${ARCH} == "amd64" )
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
CXXFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
.endif # i386
.endif

.if defined(WITH_ICC)
CC=		${LOCALBASE}/intel_cc_80/bin/icc
CXX=		${LOCALBASE}/intel_cc_80/bin/icpc
CFLAGS=		-O3 -tpp7 -axN -Vaxlib
CXXFLAGS=	-O3 -tpp7 -axN -Vaxlib
.endif

CONFIGURE_ARGS=	--x-includes="${LOCALBASE}/include" --includedir=${LOCALBASE} \
		CXXFLAGS="${CXXFLAGS} -L${LOCALBASE}/lib" \
		CFLAGS="${CFLAGS} -L${LOCALBASE}/lib" \
		LDFLAGS="-L${LOCALBASE}/lib" COMPILED_BY=${MAINTAINER} \
		--disable-optimiz

MAN1=		povray.1

post-patch:
	#@${REINPLACE_CMD} -e 's+@PREFIX@+${PREFIX}+g;' ${WRKSRC}/povray.ini
	#@${REINPLACE_CMD} -e 's+%INSTALLDIR%+${PREFIX}/share/${PORTNAME}-${PORTVERSION}+g;' ${WRKSRC}/povray.conf
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	@(cd ${WRKSRC} ; ${GMAKE} install)

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${DESCR}

.include <bsd.port.post.mk>

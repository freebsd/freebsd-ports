# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
PORTVERSION=	3.5
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/%SUBDIR%/ \
		ftp://ftp.gigabell.net/pub/unix/apps/graphics/povray/%SUBDIR%/ \
		ftp://www.hensa.ac.uk/mirrors/povray/%SUBDIR%/ \
		ftp://ftp.fh-aachen.de/pub/mirror/ftp.povray.org/povray/%SUBDIR%/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/povray/%SUBDIR%,}
MASTER_SITE_SUBDIR=	Official/Unix
DISTNAME=	povuni_s
EXTRACT_SUFX=   .tgz
DIST_SUBDIR=	povray35

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Persistence of Vision Ray Tracer

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg
.if (${MACHINE_ARCH} == "i386")
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-3.50c
USE_XLIB=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
GNU_CONFIGURE=  yes

.if defined(WITH_OPTIMIZED_FLAGS)
CFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations
CXXFLAGS+=	-O3 -ffast-math -finline-functions -fomit-frame-pointer -funroll-loops -fexpensive-optimizations -Wno-multichar
.if (${MACHINE_ARCH} == "i386" && !${MACHINE_ARCH} == "amd64" )
CFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
CXXFLAGS+=	-mfancy-math-387 -mpreferred-stack-boundary=3 -malign-double
.endif # i386
.endif

CONFIGURE_TARGET= --target=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--x-includes=${X11BASE}/include
CONFIGURE_ENV=	CXXFLAGS="${CXXFLAGS} -L${LOCALBASE}/lib -I${LOCALBASE}/include" \
		CFLAGS="${CFLAGS} -L${LOCALBASE}/lib -I${LOCALBASE}/include"

MAN1=		povray.1

post-patch:
	@${REINPLACE_CMD} -e 's+@PREFIX@+${PREFIX}+g;' ${WRKSRC}/povray.ini
	@${REINPLACE_CMD} -e 's+%INSTALLDIR%+${PREFIX}/share/${PORTNAME}-${PORTVERSION}+g;' ${WRKSRC}/povray.conf
.if !defined(WITH_OPTIMIZED_FLAGS)
	@${ECHO} "You can optimize by setting WITH_OPTIMIZED_FLAGS=yes."
.endif

do-install:
	@(cd ${WRKSRC} ; ${GMAKE} install-exec)
	@(cd ${WRKSRC} ; ${GMAKE} install-data)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} ; ${GMAKE} install-docDATA)
	@(cd ${WRKSRC}/doc ; ${GMAKE} install)
.endif
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/doc/povray.1 ${PREFIX}/man/man1

post-install:
	@${SED} -e 's,/usr/local,${PREFIX},g' ${DESCR}

.include <bsd.port.mk>

# New ports collection makefile for:    POV-Ray
# Date created:         3 Dec 1996
# Whom:                 paulo@isr.uc.pt
#
# $FreeBSD$
#

PORTNAME=	povray
PORTVERSION=	3.5
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

MAINTAINER=	chat95@mbox.kyoto-inet.or.jp

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		tiff:${PORTSDIR}/graphics/tiff \
		jpeg:${PORTSDIR}/graphics/jpeg \
		vga:${PORTSDIR}/graphics/svgalib

WRKSRC=		${WRKDIR}/${PORTNAME}-3.50b
USE_XLIB=	yes
USE_REINPLACE=  yes
USE_GMAKE=	yes
GNU_CONFIGURE=  yes
CONFIGURE_TARGET= --target=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -L${LOCALBASE}/lib -I${LOCALBASE}/include"
#		LDFLAGS="${LDFLAGS} -I${LOCALBASE}/lib"
#		CFLAGS="${CFLAGS} -L${LOCALBASE}/lib"
#		CXXFLAGS="${CXXFLAGS}
#CC="${CC}" CFLAGS="${CFLAGS}" \
#CONFIGURE_ENV=	CC="${CC}" CFLAGS="${CFLAGS}" \
#		CXXFLAGS="${CXXFLAGS} -L${LOCALBASE}/lib" \
#		CPPFLAGS="${CFLAGS} ${CPPFLAGS} -L${LOCALBASE}/lib -I${LOCALBASE}/include"
#		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
#		CXXCPP="${CXXFLAGS} ${CXXCPP} -L${LOCALBASE}/lib -I${LOCALBASE}/lib"
#CONFIGURE_ARGS= --includedir="${PREFIX}/include" --libdir="${PREFIX}/lib"

MAN1=		povray.1

post-patch:
	@${REINPLACE_CMD} -e 's+@PREFIX@+${PREFIX}+g;' ${WRKSRC}/povray.ini

do-install:
	@(cd ${WRKSRC} && ${GMAKE} install-exec)
	@(cd ${WRKSRC} &&  ${GMAKE} install-data)
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC} && ${GMAKE} install-docDATA)
	@(cd ${WRKSRC}/doc && ${GMAKE} install)
.endif
	@${RM} -f ${PREFIX}/man/man1/povray.1*
	@${INSTALL_MAN} ${WRKSRC}/doc/povray.1 ${PREFIX}/man/man1

.include <bsd.port.mk>

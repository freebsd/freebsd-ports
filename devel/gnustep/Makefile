# New ports collection makefile for:    gnustep
# Version required:     0.5.5
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.ORG>
#
# $FreeBSD$
#

DISTNAME=       gstep-core-0.5.5
PKGNAME=	gnustep-0.5.5
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.gnustep.org/pub/gnustep/core/ \
		ftp://ftp.peanuts.org/Mirrors/GNUstep/gnustep/core/

MAINTAINER=	ports@FreeBSD.ORG

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff34

BROKEN=		"Sets PREFIX in the Makefile"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=     ix86
.else
GNU_ARCH=     ${MACHINE_ARCH}
.endif
GNU_HOST=     freebsd${OSREL}
PLIST_SUB+=    GNU_ARCH=${GNU_ARCH} GNU_HOST=${GNU_HOST}

WRKSRC=		${WRKDIR}/gstep-0.5.5
PREFIX=		${LOCALBASE}/GNUstep
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c"
CONFIGURE_ARGS=	--with-library-combo=gnu-gnu-gnu-xraw \
		--with-jpeg-library=${LOCALBASE}/lib \
		--with-jpeg-include=${LOCALBASE}/include \
		--with-tiff-library=${LOCALBASE}/lib \
		--with-tiff-include=${LOCALBASE}/include
USE_GMAKE=	yes
USE_XLIB=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes
USE_NEWGCC=	yes

.include <bsd.port.post.mk>

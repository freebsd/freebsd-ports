# New ports collection makefile for:    gnustep
# Date created:         03 October 1998
# Whom:                 Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnustep
PORTVERSION=	0.6.6
CATEGORIES=	devel
MASTER_SITES=	http://ftp.codefactory.se/pub/gnu/gstep/ \
		http://planetmirror.com/pub/gnustep/core/
DISTNAME=	gstep-core-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		tiff.4:${PORTSDIR}/graphics/tiff

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
BROKEN=		"Sorry, this port does not work on FreeBSD-2.2.x"
.endif

USE_NEWGCC=	yes
PREFIX=		${LOCALBASE}/GNUstep
WRKSRC=		${WRKDIR}/${DISTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_PROGRAM="${INSTALL} -c" INSTALL_DATA="${INSTALL} -c"
CONFIGURE_ARGS=	--with-library-combo=gnu-gnu-gnu-xgps \
		--with-jpeg-library=${LOCALBASE}/lib \
		--with-jpeg-include=${LOCALBASE}/include \
		--with-tiff-library=${LOCALBASE}/lib \
		--with-tiff-include=${LOCALBASE}/include # --enable-threads=posix
CONFIGURE_TARGET=
USE_BISON=	yes
USE_GMAKE=	yes
USE_XLIB=	yes
MAKEFILE=
MAKE_FLAGS=	OPTFLAG="${CFLAGS}"
NO_MTREE=	yes

.if ${MACHINE_ARCH} == "i386"
GNU_ARCH=	ix86
.else
GNU_ARCH=	${MACHINE_ARCH}
.endif
PLIST_SUB+=	GNU_ARCH=${GNU_ARCH} VERSION=${PORTVERSION}

ETCDIR=		${PREFIX}/../etc

post-patch:
.for f in bundle gswapp gswbundle woapp wobundle
	${PERL} -pi -e 's/\$$\(TAR\) ch --exclude=CVS --to-stdout/\$$\(TAR\) -ch --exclude=CVS -f -/g' ${WRKSRC}/make/${f}.make
.endfor

post-install:
	@${MKDIR} ${ETCDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/GNUstep.sh ${ETCDIR}/rc.d
	${INSTALL_DATA} ${FILESDIR}/gdomap_if ${ETCDIR}

.include <bsd.port.post.mk>

# New ports collection makefile for:    kaffe
# Date created:         4 August 2003
# Whom:                 Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

# Configure AWT implementation used (this can be put in make.conf)
#
# KAFFE_AWT = no        No AWT classes
# KAFFE_AWT = X         X AWT classes
# KAFFE_AWT = QT        Qt AWT classes

PORTNAME=	kaffe
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/v1.1.x-development/
PKGNAMESUFFIX=	-devel

MAINTAINER=	xaa+ports@timewasters.nl
COMMENT=	Multi-platform Java virtual machine with JIT compiler and AWT package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		iconv.3:${PORTSDIR}/converters/libiconv \
		gmp.6:${PORTSDIR}/math/libgmp4

WRKSRC=		${WRKDIR}/kaffe-${PORTVERSION}

NOT_FOR_ARCHS=	amd64

USE_LIBTOOL=	yes
USE_GMAKE=	yes
LIBTOOLFLAGS=
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib --with-iconv-prefix=${LOCALBASE}

.if defined(KAFFE_AWT)
.if ${KAFFE_AWT} == "X"
  CONFIGURE_ARGS+=	--with-awt=X
  USE_XLIB=		yes
.endif
.if ${KAFFE_AWT} == "QT"
  CONFIGURE_ARGS+=	--with-awt=qt --with-qtdir=${X11BASE}
  USE_QT_VER=		3
.endif
.if ${KAFFE_AWT} == "no"
  CONFIGURE_ARGS+=	--with-awt=no
.endif
.endif

PLIST_SUB+=	PORTVER=${PORTVERSION} ARCH=${ARCH}

MAN1=		kaffe.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Broken pkg-plist"
.endif

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}

.include <bsd.port.post.mk>

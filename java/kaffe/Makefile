# New ports collection makefile for:    kaffe
# Date created:         4 August 2003
# Whom:                 Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

PORTNAME=	kaffe
PORTVERSION=	1.1.3
PORTREVISION=	1
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/v1.1.x-development/

MAINTAINER=	xaa+ports@timewasters.nl
COMMENT=	Multi-platform Java virtual machine with JIT compiler and AWT package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		gmp.6:${PORTSDIR}/math/libgmp4

CONFLICTS=	kaffe-1.[!1].* javavmwrapper-2.*

WRKSRC=		${WRKDIR}/kaffe-${PORTVERSION}

ONLY_FOR_ARCHS=	i386

USE_LIBTOOL_VER=13
USE_GMAKE=	yes
USE_ICONV=	yes
LIBTOOLFLAGS=
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib --with-iconv-prefix=${LOCALBASE}

WANT_GNOME=	esound

MAN1=		kaffe.1

OPTIONS=	AWT_X "Use AWT widgets with X" On \
		AWT_QT "Use AWT widgets with Qt" Off

.include <bsd.port.pre.mk>

.if defined(WITH_AWT_X)
. if defined(WITH_AWT_QT)
    BROKEN=	"Choose either 'X' or 'Qt' in 'make config'"
. endif
  CONFIGURE_ARGS+=	--with-awt=X
  USE_XLIB=		yes
  AWT=			yes
  WITH_ESOUND=		yes
.elif defined(WITH_AWT_QT)
  CONFIGURE_ARGS+=	--with-awt=qt --with-qtdir=${X11BASE}
  AWT=			yes
  USE_QT_VER=		3
  WITH_ESOUND=		yes
.else
  CONFIGURE_ARGS+=	--with-awt=no
.endif

.if defined(AWT)
  PLIST_SUB+=	SUB_AWT=""
.else
  PLIST_SUB+=	SUB_AWT="@comment "
.endif

.if defined(WITH_ESOUND)
  USE_GNOME+=	esound
  PLIST_SUB+=	SUB_ESOUND=""
.else
  PLIST_SUB+=	SUB_ESOUND="@comment "
.endif

PLIST_SUB+=	PORTVER=${PORTVERSION} ARCH=${ARCH}

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}

.include <bsd.port.post.mk>

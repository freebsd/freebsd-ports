# New ports collection makefile for:    kaffe
# Date created:         4 August 2003
# Whom:                 Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

PORTNAME=	kaffe
PORTVERSION=	1.1.5
CATEGORIES=	java
MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/v1.1.x-development/

MAINTAINER=	anholt@FreeBSD.org
COMMENT=	Multi-platform Java virtual machine with JIT compiler and AWT package

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		gmp.6:${PORTSDIR}/math/libgmp4

CONFLICTS=	kaffe-1.[!1].* javavmwrapper-2.*

WRKSRC=		${WRKDIR}/kaffe-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_LIBTOOL_VER=15
USE_GMAKE=	yes
USE_ICONV=	yes
LIBTOOLFLAGS=
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib --with-iconv-prefix=${LOCALBASE}

USE_GNOME=	esound gtk20 libartlgpl2
WANT_GNOME=	esound

MAN1=		kaffe.1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=    PORTVER=${PORTVERSION} ARCH=x86_64
.else
PLIST_SUB+=    PORTVER=${PORTVERSION} ARCH=${ARCH}
.endif

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}

.include <bsd.port.post.mk>

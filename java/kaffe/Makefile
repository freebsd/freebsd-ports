# New ports collection makefile for:    kaffe
# Date created:         4 August 2003
# Whom:                 Mark Huizer <xaa+ports@timewasters.nl>
#
# $FreeBSD$
#

PORTNAME=	kaffe
PORTVERSION=	1.1.7.r1
PORTREVISION=	7
CATEGORIES=	java devel
#MASTER_SITES=	ftp://ftp.kaffe.org/pub/kaffe/v1.1.x-development/
MASTER_SITES=	http://www.kaffe.org/~robilad/
DISTNAME=	${PORTNAME}-1.1.7-rc1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-platform Java virtual machine with JIT compiler and AWT package

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		ungif.5:${PORTSDIR}/graphics/libungif \
		png.5:${PORTSDIR}/graphics/png \
		gmp.8:${PORTSDIR}/math/libgmp4
BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		jikes:${PORTSDIR}/java/jikes
RUN_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		javavm:${PORTSDIR}/java/javavmwrapper

#WRKSRC=		${WRKDIR}/kaffe-${PORTVERSION}

ONLY_FOR_ARCHS=	i386 amd64

USE_XORG=	x11 ice xtst
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	CPPFLAGS=-I${LOCALBASE}/include \
		LDFLAGS=-L${LOCALBASE}/lib \
		--with-iconv-prefix=${LOCALBASE}
PREFIX=		${LOCALBASE}/kaffe
NO_MTREE=	yes

USE_GNOME=	esound gtk20 libartlgpl2
WANT_GNOME=	esound

MAN1=		fastjar.1 kaffe.1

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
PLIST_SUB+=    PORTVER=1.1.7-rc1 ARCH=x86_64
.else
PLIST_SUB+=    PORTVER=1.1.7-rc1 ARCH=${ARCH}
.endif

post-install:
	@${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/BUILD_ENVIRONMENT ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/license.terms ${DATADIR}
	-@${LOCALBASE}/bin/registervm ${PREFIX}/bin/java

.include <bsd.port.post.mk>

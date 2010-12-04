# New ports collection makefile for:	OO2C
# Date created:				December 17, 1999
# Whom:					Oliver Breuninger <ob@seicom.NET>
#
# $FreeBSD$

PORTNAME=	oo2c
PORTVERSION=	2.1.11
CATEGORIES=	lang
MASTER_SITES=	SF/ooc/ooc2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${BITS}-${PORTVERSION}

MAINTAINER=	johans@FreeBSD.org
COMMENT=	Optimizing Oberon-2 compiler of University of Kaiserslautern, Germany

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc

DOCSDIR=	lib/${PORTNAME}
USE_BZIP2=	yes
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DGC_PTR='void*'" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		oo2c.1 oob.1 ooef.1 oowhereis.1

ONLY_FOR_ARCHS=	i386 amd64 ia64

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BITS=		32
.else
BITS=		64
.endif

.include <bsd.port.post.mk>

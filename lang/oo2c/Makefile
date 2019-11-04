# Created by: Oliver Breuninger <ob@seicom.NET>
# $FreeBSD$

PORTNAME=	oo2c
PORTVERSION=	2.1.11
PORTREVISION=	13
CATEGORIES=	lang
MASTER_SITES=	SF/ooc/ooc2/${PORTVERSION}
DISTNAME=	${PORTNAME}_${BITS}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Optimizing Oberon-2 compiler of University of Kaiserslautern, Germany

LICENSE=	GPLv2

BUILD_DEPENDS=	xsltproc:textproc/libxslt
RUN_DEPENDS=	libtool:devel/libtool
LIB_DEPENDS=	libgc.so:devel/boehm-gc

ONLY_FOR_ARCHS=		amd64 i386

DOCSDIR=	lib/${PORTNAME}
USES=		gmake libtool:build tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_CSTD=	gnu89
USE_GCC=	any
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's/dir=@/dir=$${DESTDIR}@/' \
		 ${WRKSRC}/Makefile.config.in
	@${REINPLACE_CMD} -e 's|@PERL@|${LOCALBASE}/bin/perl|' \
		${WRKSRC}/rsrc/OOC/oobacktrace.in

.include <bsd.port.pre.mk>

.if ${ARCH} == i386
BITS=		32
.else
BITS=		64
.endif

.include <bsd.port.post.mk>

# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	squirrel
PORTVERSION=	2.2.5
CATEGORIES=	lang
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}2/${PORTNAME}%20${PORTVERSION}%20stable
DISTNAME=	${PORTNAME}_${DISTVERSION}_stable

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High level imperative/OO programming language

CONFLICTS=	squsq-[0-9]*

USES=		dos2unix
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/SQUIRREL2

CFLAGS_aarch64=	-fPIC
CFLAGS_amd64=	-fPIC
CFLAGS_sparc64=	-fPIC

.include <bsd.port.pre.mk>

.if ${ARCH} == aarch64 || ${ARCH} == amd64 || ${ARCH} == sparc64
ALL_TARGET=	sq64
.else
ALL_TARGET=	sq32
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile | ${XARGS} ${REINPLACE_CMD} \
		-e '/^MAKE/d; s|gcc|$${CC}|; s|-O2|$${CFLAGS}|; s|g++|$${CXX}|' \
		-e 's|\.a|.so|g; s|ar rc|$${CC} ${CFLAGS} -shared -o|'
	@${REINPLACE_CMD} -e '/cd / s|$$|\&\& cd ..|' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/sq ${STAGEDIR}${PREFIX}/bin
	(cd ${WRKSRC}/lib && ${INSTALL_LIB} libsqstdlib.so libsquirrel.so \
		${STAGEDIR}${PREFIX}/lib)
	@${LN} -sf libsqstdlib.so ${STAGEDIR}${PREFIX}/lib/libsqstdlib.so.0
	@${LN} -sf libsquirrel.so ${STAGEDIR}${PREFIX}/lib/libsquirrel.so.0
	${INSTALL_DATA} ${WRKSRC}/include/*.h ${STAGEDIR}${PREFIX}/include

.include <bsd.port.post.mk>

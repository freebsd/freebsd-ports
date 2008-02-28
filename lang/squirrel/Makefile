# New ports collection makefile for:	squirrel
# Date created:		14 July 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	squirrel
PORTVERSION=	2.2
CATEGORIES=	lang
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}_${DISTVERSION}_stable

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	High level imperative/OO programming language

CONFLICTS=	squsq-[0-9]*
USE_DOS2UNIX=	yes
USE_LDCONFIG=	yes
WRKSRC=		${WRKDIR}/SQUIRREL2
SHORTINCS=	stdaux stdblob stdio stdmath stdstring stdsystem uirrel
FULLINCS=	${SHORTINCS:S|^|sq|:S|$|.h|}
PLIST_FILES=	bin/sq lib/libsqstdlib.so lib/libsqstdlib.so.0\
		lib/libsquirrel.so lib/libsquirrel.so.0\
		${FULLINCS:S|^|include/|}

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64 || ${ARCH} == sparc64 || ${ARCH} == ia64
ALL_TARGET=	sq64
CFLAGS+=	-fPIC
.else
ALL_TARGET=	sq32
.endif

post-patch:
	@${FIND} ${WRKSRC} -name Makefile|${XARGS} ${REINPLACE_CMD}\
		-e '/^MAKE/d;s|gcc|$${CC}|;s|-O2|$${CFLAGS}|;s|g++|$${CXX}|'\
		-e 's|\.a|.so|g;s|ar rc|$${CC} ${CFLAGS} -shared -o|'

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/bin/sq ${PREFIX}/bin/
	@cd ${WRKSRC}/lib&&${INSTALL_PROGRAM} libsqstdlib.so libsquirrel.so\
		${PREFIX}/lib/
	@${LN} -sf libsqstdlib.so ${PREFIX}/lib/libsqstdlib.so.0
	@${LN} -sf libsquirrel.so ${PREFIX}/lib/libsquirrel.so.0
	@cd ${WRKSRC}/include&&${INSTALL_DATA} ${FULLINCS}\
		${PREFIX}/include/

.include <bsd.port.post.mk>

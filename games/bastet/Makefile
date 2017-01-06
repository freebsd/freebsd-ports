# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bastet
PORTVERSION=	0.43
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses Tetris clone which is harder than every other Tetris

LICENSE=	GPLv3+

BROKEN_powerpc64=	Does not build

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		gmake ncurses tar:tgz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/bastet man/man6/bastet.6.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 1000024
.if exists(/usr/bin/clang)
CC=		clang
CXX=		clang++
CPP=		clang-cpp
.else
.if ${ARCH} == "i386"
CXXFLAGS+=	-fexceptions
.else
USE_GCC=	yes
.endif
.endif
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS+=-D|CXXFLAGS+=$$(CPPFLAGS) -D| ; \
		 s|$$(CXX) -MM|$$(CXX) $$(CXXFLAGS) -MM| ; \
		 s| -ggdb | |' ${WRKSRC}/Makefile

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} bastet \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} bastet.6 \
		${STAGEDIR}${MAN6PREFIX}/man/man6)

.include <bsd.port.post.mk>

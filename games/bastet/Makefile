# Created by: Michael Nottebrock <lofi@freebsd.org>
# $FreeBSD$

PORTNAME=	bastet
PORTVERSION=	0.43
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses Tetris clone which is harder than every other Tetris

LICENSE=	GPLv3 # (or later)

LIB_DEPENDS=	boost_program_options:${PORTSDIR}/devel/boost-libs

USES=		ncurses
USE_GMAKE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		bastet.6
PLIST_FILES=	bin/bastet

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
USE_GCC=	yes
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS+=-D|CXXFLAGS+=$$(CPPFLAGS) -D| ; \
		 s|$$(CXX) -MM|$$(CXX) $$(CPPFLAGS) -MM| ; \
		 s| -ggdb | |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${MAN6PREFIX}/man/man6

.include <bsd.port.post.mk>

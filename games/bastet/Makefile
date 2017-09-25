# Created by: Michael Nottebrock <lofi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bastet
PORTVERSION=	0.43
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ncurses Tetris clone which is harder than every other Tetris

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_powerpc64=	does not build

LIB_DEPENDS=	libboost_program_options.so:devel/boost-libs

USES=		gmake localbase:ldflags ncurses tar:tgz

PLIST_FILES=	bin/bastet man/man6/bastet.6.gz

post-patch:
	@${REINPLACE_CMD} -e \
		's|^CXXFLAGS+=-D|CXXFLAGS+=$$(CPPFLAGS) -D| ; \
		 s|$$(CXX) -MM|$$(CXX) $$(CXXFLAGS) -MM| ; \
		 s| -ggdb | |' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bastet ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/bastet.6 ${STAGEDIR}${MAN6PREFIX}/man/man6

.include <bsd.port.mk>

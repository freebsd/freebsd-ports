# New ports collection makefile for:    bastet
# Date created:         21 Oct 2004
# Whom:                	Michael Nottebrock <lofi@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	bastet
PORTVERSION=	0.43
CATEGORIES=	games
MASTER_SITES=	http://fph.altervista.org/prog/files/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An ncurses Tetris clone which is harder than every other Tetris

LICENSE=	GPLv3 # (or later)

LIB_DEPENDS=	boost_program_options:${PORTSDIR}/devel/boost-libs

USE_NCURSES=	yes
USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MAN6=		bastet.6
PLIST_FILES=	bin/bastet

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
USE_GCC=	4.6+
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

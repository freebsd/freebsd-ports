# Created by: Joel Sutton <jsutton@bbcon.com.au>
# $FreeBSD$

PORTNAME=	oonsoo
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SUNSITE/games/solitaires \
		http://www4.ncsu.edu/~bwmott/www/oonsoo/distributions/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Solitaire card game for X

USES=		xorg
USE_XORG=	x11
PLIST_FILES=	bin/oonsoo
MAKEFILE=	Makefile.Linux
MAKE_ARGS=	CC="${CXX}" CPPFLAGS="${CXXFLAGS} -ansi"	\
		SYS_INCLUDE="-I${LOCALBASE}/include"		\
		SYS_LIBS="-L${LOCALBASE}/lib -lX11"
MAKE_JOBS_UNSAFE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/oonsoo ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

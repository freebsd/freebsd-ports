# Created by: Kay Lehmann <kay_lehmann@web.de>
# $FreeBSD$

PORTREVISION=	1

COMMENT=	Qt MySQL database plugin
DB=		mysql
USE_MYSQL=	yes

CXXFLAGS+=	-I${LOCALBASE}/include/mysql
LDFLAGS+=	-L${LOCALBASE}/lib/mysql

BROKEN_powerpc64=	Does not build

.include "${.CURDIR:H:H}/devel/qt4/Makefile.sqldrivers"

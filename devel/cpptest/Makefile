# Created by: Fernando Apesteguia <fernando.apesteguia@gmail.com>
# $FreeBSD$

PORTNAME=	cpptest
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
#http://downloads.sourceforge.net/project/cpptest/cpptest/cpptest-1.1.2/cpptest-1.1.2.tar.gz?r=http%3A%2F%2Fsourceforge.net%2Fprojects%2Fcpptest%2F&ts=1406744543&use_mirror=heanet

MAINTAINER=	fernando.apesteguia@gmail.com
COMMENT=	Unit testing framework for handling automated tests in C++

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
USES=		gmake libtool
USE_LDCONFIG=	yes
MAKE_ARGS=	CC=${CC} CCC=${CXX}

post-install:
	@${MV} ${STAGEDIR}${PREFIX}/lib/pkgconfig/libcpptest.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/libcpptest.pc
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libcpptest.so.0.0.7

.include <bsd.port.mk>

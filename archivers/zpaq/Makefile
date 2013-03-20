# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zpaq
PORTVERSION=	6.22
CATEGORIES=	archivers
MASTER_SITES=	http://mattmahoney.net/dc/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Journaling, incremental, deduplicating archiver

LICENSE=	GPLv3

USE_ZIP=	yes
USE_DOS2UNIX=	zpaq.cpp
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/zpaq bin/zpaqd

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
CXXFLAGS+=	-DNOJIT
.endif

do-build:
	cd ${BUILD_WRKSRC} && ${CXX} ${CXXFLAGS} -Dunix -DNDEBUG zpaq.cpp \
		libzpaq.cpp divsufsort.c -o zpaq -fopenmp -pthread
	cd ${BUILD_WRKSRC} && ${CXX} ${CXXFLAGS} -Dunix zpaqd.cpp \
		libzpaq.cpp -o zpaqd

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zpaq ${WRKSRC}/zpaqd ${PREFIX}/bin

.include <bsd.port.post.mk>

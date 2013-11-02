# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	qpress
PORTVERSION=	1.1
CATEGORIES=	archivers
MASTER_SITES=	http://www.quicklz.com/
DISTNAME=	qpress-11-source

MAINTAINER=	samm@os2.kiev.ua
COMMENT=	Portable file archiver using QuickLZ

LICENSE=	GPLv2

EXTRACT_AFTER_ARGS=	-d ${WRKSRC}
USE_ZIP=	yes
USE_DOS2UNIX=	yes

NO_STAGE=	yes
PLIST_FILES=	bin/qpress

do-build:
	cd ${WRKSRC} && \
	${CXX} ${CXXFLAGS} -o qpress qpress.cpp aio.cpp quicklz.c utilities.cpp -lpthread

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qpress ${DESTDIR}${PREFIX}/bin

.include <bsd.port.mk>

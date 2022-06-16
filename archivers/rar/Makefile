# Created by: ache

PORTNAME=	rar
PORTVERSION=	6.12
PORTEPOCH=	3
CATEGORIES=	archivers
MASTER_SITES=	https://rarlab.com/rar/
DISTNAME=	rarbsd${ARCH:S|amd64|-x64|:S|i386|-x32|}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File archiver (binary port)

LICENSE=	RAR
LICENSE_NAME=	RAR license
LICENSE_FILE=	${WRKSRC}/license.txt
# Only unmodified original package can be distributed
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

ONLY_FOR_ARCHS=	amd64 i386

USES=		cpe

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

PLIST_FILES=	bin/rar etc/rarfiles.lst lib/default.sfx man/cat1/rar.1.gz

CPE_VENDOR=	rarlab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${STAGEDIR}${PREFIX}/man/cat1/rar.1

# maintainer section:

.if defined(MAINTAINER_MODE)
DISTFILES=	rarbsd-x32-${PORTVERSION:R}${PORTVERSION:E}.tar.gz \
		rarbsd-x64-${PORTVERSION:R}${PORTVERSION:E}.tar.gz
.endif

.include <bsd.port.mk>

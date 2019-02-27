# Created by: ache
# $FreeBSD$

PORTNAME=	rar
PORTVERSION=	5.7.0
PORTEPOCH=	3
CATEGORIES=	archivers
MASTER_SITES=	https://rarlab.com/rar/
DISTNAME=	rarbsd${ARCH:S|amd64|-x64|:S|i386||}-${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File archiver (binary port)

LICENSE=	RAR
LICENSE_NAME=	RAR license
LICENSE_FILE=	${WRKSRC}/license.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

ONLY_FOR_ARCHS=	amd64 i386
RESTRICTED=	only unmodified original package can be distributed

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

PLIST_FILES=	bin/rar lib/default.sfx etc/rarfiles.lst man/cat1/rar.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${STAGEDIR}${PREFIX}/man/cat1/rar.1
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>

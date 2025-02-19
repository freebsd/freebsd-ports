PORTNAME=	rar
PORTVERSION=	7.01
CATEGORIES=	archivers
MASTER_SITES=	https://www.rarlab.com/rar/
DISTNAME=	rarbsd-x32-${PORTVERSION:R}${PORTVERSION:E}
PKGNAMESUFFIX=	-i386

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	File archiver (binary port, legacy version for i386 only)
WWW=		https://www.rarlab.com/

LICENSE=	RAR
LICENSE_NAME=	RAR license
LICENSE_FILE=	${WRKSRC}/license.txt
# Only unmodified original package can be distributed
LICENSE_PERMS=	auto-accept dist-mirror pkg-mirror

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	amd64 users should use archivers/rar

USES=		cpe

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/rar

PLIST_FILES=	bin/rar etc/rarfiles.lst lib/default.sfx share/man/cat1/rar.1.gz

CPE_VENDOR=	rarlab

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/rar ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/rarfiles.lst ${STAGEDIR}${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/default.sfx ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/rar.txt ${STAGEDIR}${PREFIX}/share/man/cat1/rar.1

.include <bsd.port.mk>

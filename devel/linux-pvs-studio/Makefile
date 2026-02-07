PORTNAME=	pvs-studio
PORTVERSION=	7.39
DISTVERSIONSUFFIX=	.99307.684
CATEGORIES=	devel linux
MASTER_SITES=	https://cdn.pvs-studio.com/
PKGNAMEPREFIX=	linux-
EXTRACT_SUFX=	-x86_64.rpm

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	PVS-Studio is a static analyzer tool for C, C++, C# and Java
WWW=		https://pvs-studio.com

LICENSE=	commercial
LICENSE_NAME=	commercial
LICENSE_TEXT=	Commercial software with 30 days trial period
LICENSE_PERMS=	dist-mirror pkg-mirror auto-accept

ONLY_FOR_ARCHS=	amd64

USES=		linux:rl9 shebangfix

USE_LINUX=	base curl strace

WRKSRC=		${WRKDIR}
NO_BUILD=	yes
PLIST_SUB=	LINUXBASE=${LINUXBASE}
STRIP=

PLIST_SUB+=	QT=${DISTVERSIONFULL:R:R}.99095.1484 VSCODE=${DISTVERSIONFULL:R:R}.99113

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/pvs-* ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKDIR}/usr/bin/plog-* ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKDIR}/usr/lib && ${CP} -r pvs-studio ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>

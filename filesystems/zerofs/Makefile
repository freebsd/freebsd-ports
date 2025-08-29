PORTNAME=	zerofs
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.5
CATEGORIES=	filesystems sysutils

MAINTAINER= 	stephan@lichtenauer.co.za
COMMENT=	ZeroFS is 9P/NFS/NBD on top of S3
WWW=		https://github.com/Barre/ZeroFS

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKDIR}/ZeroFS-${DISTVERSION}/LICENSE

USES=           cargo gmake

WRKSRC=         ${WRKDIR}/ZeroFS-${DISTVERSION}/zerofs

USE_GITHUB=	yes
GH_ACCOUNT=	Barre
GH_PROJECT=	ZeroFS
PLIST_FILES=	bin/zerofs

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/target/release/zerofs ${STAGEDIR}${PREFIX}/bin/zerofs

.include <bsd.port.mk>

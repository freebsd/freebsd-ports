PORTNAME=	sasquatch
DISTVERSION=	4.3
CATEGORIES=	filesystems sysutils

MAINTAINER=	tiago.gasiba@gmail.com
COMMENT=	SquashFS extractor with patches for firmware analysis
WWW=		https://gitlab.com/tgasiba/sasquatch/

LICENSE=		CPL GPLv2 LGPL21 PUBLIC
LICENSE_COMB=		multi
LICENSE_NAME_CPL=	Common Public License V. 1.0
LICENSE_NAME_PUBLIC=	Public Domain
LICENSE_FILE_CPL=	${WRKSRC}/LZMA/lzmadaptive/CPL.html
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE
LICENSE_FILE_LGPL21=	${WRKSRC}/LZMA/lzmadaptive/LGPL.txt
LICENSE_FILE_PUBLIC=	${WRKSRC}/LZMA/lzma465/lzma.txt
LICENSE_PERMS_CPL=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_PERMS_PUBLIC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		liblzo2.so:archivers/lzo2

USES=		compiler:c++11-lang
USE_GITLAB=	yes
GL_ACCOUNT=	tgasiba

MAKE_ENV=	CC="${CC}" \
		CXX="${CXX}"

PLIST_FILES=	bin/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

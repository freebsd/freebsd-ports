PORTNAME=	hfsfuse
DISTVERSION=	0.289
CATEGORIES=	filesystems
MASTER_SITES=	https://github.com/0x09/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	me@cameronkatri.com
COMMENT=	FUSE driver for HFS+ filesystems
WWW=		https://github.com/0x09/hfsfuse

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libublio.so:devel/libublio \
		libutf8proc.so:textproc/utf8proc \
		liblzfse.so:archivers/lzfse

USES=		fuse gmake libarchive
USE_CSTD=	gnu11

ALL_TARGET=	config all

PLIST_FILES=	bin/hfsdump \
		bin/hfsfuse \
		bin/hfstar

PORTDOCS=	README.md

MAKE_ARGS=	CONFIG_CFLAGS="${CFLAGS}" \
		WITH_UBLIO=system \
		WITH_UTF8PROC=system

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/hfsdump ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hfsfuse ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hfstar ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

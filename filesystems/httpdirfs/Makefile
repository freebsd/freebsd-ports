PORTNAME=	httpdirfs
DISTVERSION=	1.2.7
PORTREVISION=	3
CATEGORIES=	filesystems
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	alven@FreeBSD.org
COMMENT=	FUSE filesystem to mount HTTP directory listings, with a permanent cache
WWW=		https://github.com/fangfufu/httpdirfs/

LICENSE=	GPL3OPENSSL
LICENSE_NAME=	GPLv3 or later with execption to link with OpenSSL
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libcurl.so:ftp/curl \
		libexpat.so:textproc/expat2 \
		libgumbo.so:devel/gumbo \
		libuuid.so:misc/libuuid

USES=		fuse:3 meson pkgconfig ssl
USE_GITHUB=	yes
GH_ACCOUNT=	fangfufu

PLIST_FILES=	bin/httpdirfs
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

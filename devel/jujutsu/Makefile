PORTNAME=	jujutsu
DISTVERSIONPREFIX=	v
DISTVERSION=	0.20.0
CATEGORIES=	devel

MAINTAINER=	se@FreeBSD.org
COMMENT=	Git-compatible VCS that is both simple and powerful
WWW=		https://github.com/martinvonz/jj/blob/main/README.md

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
                libssh2.so:security/libssh2 \
                libzstd.so:archivers/zstd

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	martinvonz
GH_PROJECT=	jj

PLIST_FILES=	bin/jj

do-install:
		${INSTALL_PROGRAM} ${WRKDIR}/target/*-unknown-freebsd/release/jj \
			${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>

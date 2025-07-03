PORTNAME=	termscp
DISTVERSIONPREFIX=	v
DISTVERSION=	0.10.0
PORTREVISION=	24
CATEGORIES=	ftp

MAINTAINER=	sec.research.2005@gmail.com
COMMENT=	TUI file transfer and explorer with support for SCP/SFTP/FTP/S3
WWW=		https://github.com/veeso/termscp

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	gmake:devel/gmake
LIB_DEPENDS=	libdbus-1.so:devel/dbus \
		libssh2.so:security/libssh2

USES=		cargo perl5
USE_PERL5=	build

USE_GITHUB=	yes
GH_ACCOUNT=	veeso

CARGO_FEATURES=	--no-default-features

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=		DOCS
OPTIONS_DEFAULT=	DOCS

PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} *.md docs/man.md ${STAGEDIR}${DOCSDIR}

.include "${.CURDIR}/bsd.termscp.mk"
.include <bsd.port.mk>

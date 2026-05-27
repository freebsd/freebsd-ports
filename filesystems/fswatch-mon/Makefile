PORTNAME=	fswatch
DISTVERSION=	1.20.1
CATEGORIES=	filesystems sysutils
MASTER_SITES=	https://github.com/emcrisostomo/${PORTNAME}/releases/download/${DISTVERSION}/
PKGNAMESUFFIX=	-mon

MAINTAINER=	enrico.m.crisostomo@gmail.com
COMMENT=	Cross-platform file change monitor
WWW=		https://github.com/emcrisostomo/fswatch

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c++17-lang libtool makeinfo
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	fswatch
GNU_CONFIGURE=	yes
INFO=	fswatch
INSTALL_TARGET=	install-strip
LIBS=		-lpthread

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

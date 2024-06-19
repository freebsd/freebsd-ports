PORTNAME=	mscompress
DISTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	archivers

MAINTAINER=	mew14930xvi@inbox.lv
COMMENT=	Microsoft "compress.exe/expand.exe" compatible (de)compressor
WWW=		https://github.com/stapelberg/mscompress

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	stapelberg

HAS_CONFIGURE=	yes

CONFLICTS_INSTALL=	foo2zjs # bin/msexpand

PLIST_FILES=	bin/mscompress bin/msexpand \
		share/man/man1/mscompress.1.gz \
		share/man/man1/msexpand.1.gz

.include <bsd.port.mk>

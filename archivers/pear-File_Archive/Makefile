PORTNAME=	File_Archive
PORTVERSION=	1.5.5
CATEGORIES=	archivers www pear

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	PEAR class to manipulate tar, gz, tgz, bz2, tbz, zip, ar (deb) files

LICENSE=	LGPL3

RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}MIME_Type>=0:mail/pear-MIME_Type@${PHP_FLAVOR}

USES=		pear
USE_PHP=	bz2 pcre zlib

NO_ARCH=	yes

OPTIONS_DEFINE=	PEAR_CACHE_LITE PEAR_MAIL PEAR_MAIL_MIME
PEAR_CACHE_LITE_DESC=	PEAR::Cache_Lite support
PEAR_MAIL_DESC=		PEAR::Mail support
PEAR_MAIL_MIME_DESC=	PEAR::Mail_Mime support

PEAR_CACHE_LITE_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Cache_Lite>=1.5.0:sysutils/pear-Cache_Lite@${PHP_FLAVOR}
PEAR_MAIL_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Mail>=0:mail/pear-Mail@${PHP_FLAVOR}
PEAR_MAIL_MIME_RUN_DEPENDS=	${PEAR_PKGNAMEPREFIX}Mail_Mime>=0:mail/pear-Mail_Mime@${PHP_FLAVOR}

.include <bsd.port.mk>

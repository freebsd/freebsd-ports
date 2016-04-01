# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	File_Archive
PORTVERSION=	1.5.5
CATEGORIES=	archivers www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to manipulate tar, gz, tgz, bz2, tbz, zip, ar (deb) files

BUILD_DEPENDS=	${PEARDIR}/MIME/Type.php:mail/pear-MIME_Type
RUN_DEPENDS=	${PEARDIR}/MIME/Type.php:mail/pear-MIME_Type

USES=		pear
NO_ARCH=	yes

USE_PHP=	bz2 pcre zlib

OPTIONS_DEFINE=	PEAR_MAIL PEAR_MAIL_MIME PEAR_CACHE_LITE

PEAR_MAIL_DESC=		PEAR::Mail support
PEAR_MAIL_MIME_DESC=	PEAR::Mail_Mime support
PEAR_CACHE_LITE_DESC=	PEAR::Cache_Lite support

PEAR_MAIL_RUN_DEPENDS=	${PEARDIR}/Mail.php:mail/pear-Mail
PEAR_MAIL_MIME_RUN_DEPENDS=	${PEARDIR}/Mail/mime.php:mail/pear-Mail_Mime
PEAR_CACHE_LITE_RUN_DEPENDS+=	${PEARDIR}/Cache/Lite.php:sysutils/pear-Cache_Lite

.include <bsd.port.mk>

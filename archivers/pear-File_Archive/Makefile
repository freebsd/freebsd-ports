# Created by: Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
# $FreeBSD$

PORTNAME=	File_Archive
PORTVERSION=	1.5.5
CATEGORIES=	archivers www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR class to manipulate tar, gz, tgz, bz2, tbz, zip, ar (deb) files

BUILD_DEPENDS=	${PEARDIR}/MIME/Type.php:${PORTSDIR}/mail/pear-MIME_Type \
		${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/MIME/Type.php:${PORTSDIR}/mail/pear-MIME_Type \
		${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

USE_PHP=	bz2 pcre zlib
LATEST_LINK=	pear-${PORTNAME}

OPTIONS_DEFINE=	PEAR_MAIL PEAR_MAIL_MIME PEAR_CACHE_LITE

PEAR_MAIL_DESC=		"PEAR::Mail support"
PEAR_MAIL_MIME_DESC=	"PEAR::Mail_Mime support"
PEAR_CACHE_LITE_DESC=	"PEAR::Cache_Lite support"

PEAR_AUTOINSTALL=	YES

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MWITH_PEAR_MAIL}
RUN_DEPENDS+=	${PEARDIR}/Mail.php:${PORTSDIR}/mail/pear-Mail
.endif

.if ${PORT_OPTIONS:MPEAR_MAIL_MIME}
RUN_DEPENDS+=	${PEARDIR}/Mail/mime.php:${PORTSDIR}/mail/pear-Mail_Mime
.endif

.if ${PORT_OPTIONS:MPEAR_CACHE_LITE}
RUN_DEPENDS+=	${PEARDIR}/Cache/Lite.php:${PORTSDIR}/sysutils/pear-Cache_Lite
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>

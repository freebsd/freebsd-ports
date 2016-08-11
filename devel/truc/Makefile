# Created by: Jan Siml <jsi@jules.de>
# $FreeBSD$

PORTNAME=	truc
PORTVERSION=	0.12.0
PORTREVISION=	3
CATEGORIES=	devel www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/TRUC%20Testing%20${PORTVERSION}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jsi@jules.de
COMMENT=	Web-based tool for requirement and use case tracking

BROKEN_powerpc64=	Does not build

NO_BUILD=	yes
USE_PHP=	mysqli gd

USES=		cpe shebangfix
SHEBANG_FILES=	FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl \
		FCKeditor/editor/filemanager/browser/mcpuk/connectors/php/commands/helpers/header.cgi \
		FCKeditor/editor/filemanager/browser/mcpuk/connectors/php/commands/helpers/progress.cgi \
		FCKeditor/editor/filemanager/browser/mcpuk/connectors/php/commands/helpers/upload.cgi
CPE_VENDOR=	jan_schutze
PLIST_SUB=	WWWOWN="${WWWOWN}" WWWGRP="${WWWGRP}"
SUB_LIST=	"PKGNAME=${PKGNAME}"
SUB_FILES=	pkg-message

WANT_PHP_WEB=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/truc
#	${MV} ${WRKSRC}/config_inc.php ${WRKSRC}/config_inc.php-dist
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${PREFIX}/www/truc

.include <bsd.port.mk>

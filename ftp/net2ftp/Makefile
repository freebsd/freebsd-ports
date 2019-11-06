# Created by: Alexander Kriventsov
# $FreeBSD$

PORTNAME=	net2ftp
PORTVERSION=	1.3
CATEGORIES=	ftp
MASTER_SITES=	https://www.net2ftp.com/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Web-based FTP client written in PHP

BROKEN=		unfetchable

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/files_to_upload/LICENSE.txt

USES=		php zip
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ftp mysqli pcre session zlib
.endif

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

post-patch:
	@${FIND} ${WRKSRC}/files_to_upload -name 'settings*.inc.php' | ${XARGS} -I % ${MV} % %.sample

do-install:
	cd ${WRKSRC}/files_to_upload && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

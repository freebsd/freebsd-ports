PORTNAME=	net2ftp
PORTVERSION=	1.4
CATEGORIES=	ftp
MASTER_SITES=	https://www.net2ftp.com/download/
DISTNAME=	net2ftp_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based FTP client written in PHP
WWW=		https://www.net2ftp.com/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe php zip
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ftp mysqli session zlib
.endif

NO_ARCH=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

post-patch:
	@${FIND} ${WRKSRC}/files_to_upload -name 'settings*.inc.php' | ${XARGS} -I % ${MV} % %.sample

do-install:
	cd ${WRKSRC}/files_to_upload && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR}

.include <bsd.port.mk>

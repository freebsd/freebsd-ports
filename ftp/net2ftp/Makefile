# Created by: Alexander Kriventsov
# $FreeBSD$

PORTNAME=	net2ftp
PORTVERSION=	1.1
CATEGORIES=	ftp
MASTER_SITES=	http://www.net2ftp.com/download/
DISTNAME=	${PORTNAME}_v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based FTP client written in PHP

LICENSE=	GPLv2

USES=		php zip
NO_BUILD=	YES
.if !defined(WITHOUT_PHP_DEPENDS)
USE_PHP=	ftp mysqli pcre session zlib
.endif

SUB_FILES+=	pkg-message

do-install:
	@(for samplefile in $$( ${FIND} ${WRKSRC}/files_to_upload -name "settings*.inc.php" ) ; do \
		${MV} $$samplefile $$samplefile.sample ; \
	done)
	@(cd ${WRKSRC}/files_to_upload && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR})

.include <bsd.port.mk>

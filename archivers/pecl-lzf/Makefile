# New ports collection makefile for:	pecl-lzf
# Date created:			2006/09/07
# Whom:				chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	lzf
PORTVERSION=	1.5.2
CATEGORIES=	archivers pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Handles LZF de/compression

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--enable-lzf
WRKSRC=		${WRKDIR}/${DISTNAME:U}

OPTIONS=	BETTER_COMPRESSION	"Better compression ratio"	off

.if defined(WITH_BETTER_COMPRESSION)
CONFIGURE_ARGS+=	--enable-lzf-better-compression
	@${ECHO_MSG} "--enable-lzf-better-compression"
.endif

.include <bsd.port.mk>

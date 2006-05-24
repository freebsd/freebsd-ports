# New ports collection makefile for:	pecl-imagick
# Date created:			19 Jul 2004
# Whom:				Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	imagick
PORTVERSION=	0.9.11
PORTREVISION=	5
CATEGORIES=	graphics pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	ale@FreeBSD.org
COMMENT=	A PECL extension to manipulate images

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ARGS=	--with-imagick=${LOCALBASE}

OPTIONS=	GM "Use GraphicsMagick backend" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GM)
LIB_DEPENDS=	Magick.10:${PORTSDIR}/graphics/ImageMagick
.else
LIB_DEPENDS=	GraphicsMagick.1:${PORTSDIR}/graphics/GraphicsMagick
CONFIGURE_ARGS+=--with-imagick-gm
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>

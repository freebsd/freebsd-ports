# New ports collection makefile for:	pecl-statgrab
# Date created:			04 April 2005
# Whom:				Tim Bishop <tim@bishnet.net>
#
# $FreeBSD$
#

PORTNAME=	statgrab
PORTVERSION=	0.4
PORTREVISION=	2
CATEGORIES=	devel pear
MASTER_SITES=	http://pecl.php.net/get/
PKGNAMEPREFIX=	pecl-
DISTNAME=	Statgrab-${PORTVERSION}
EXTRACT_SUFX=	.tgz
DIST_SUBDIR=	PECL

MAINTAINER=	tim@bishnet.net
COMMENT=	A PECL extension to retrieve information from libstatgrab

LIB_DEPENDS=	statgrab.7:${PORTSDIR}/devel/libstatgrab

USE_PHP=	yes
USE_PHPEXT=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -ldevstat ${EXTRA_LIBS}"

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
EXTRA_LIBS=	-lkvm
.endif

.if ${PHP_VER} < 5
post-patch:
	@${PATCH} -d ${WRKSRC} -p0 < ${FILESDIR}/php_statgrab.h.patch
.endif

.include <bsd.port.post.mk>

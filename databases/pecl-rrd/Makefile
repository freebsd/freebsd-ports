PORTNAME=	rrd
DISTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	databases pear

MAINTAINER=	flo@FreeBSD.org
COMMENT=	PHP bindings to rrd tool system
WWW=		https://pecl.php.net/package/rrd

LICENSE=	PHP301

LIB_DEPENDS=	librrd.so:databases/rrdtool
USES=		php:pecl localbase pkgconfig

.include <bsd.port.pre.mk>

post-patch:
.if ${PHP_VER} >= 85
	@${REINPLACE_CMD} -e 's|ext/standard/php_smart_string|Zend/zend_smart_string|' \
		${WRKSRC}/rrd.c ${WRKSRC}/rrd_graph.c ${WRKSRC}/rrd_update.c
.endif

.include <bsd.port.post.mk>

# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swfed
PORTVERSION=	0.62
PORTREVISION=	4
CATEGORIES=	graphics www
MASTER_SITES=	SFJP/${PORTNAME}/60548
PKGNAMEPREFIX=	php5-

MAINTAINER=	yoya@awm.jp
COMMENT=	PHP extension to edit SWF file

LICENSE=	PHP301

DEPRECATED=	PHP 5.4 EOL reached
EXPIRATION_DATE=	2016-01-15

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	libgif.so:${PORTSDIR}/graphics/giflib \
		libpng.so:${PORTSDIR}/graphics/png

DEFAULT_PHP_VER=	5
USE_PHP=	zlib
USE_PHPEXT=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/src
CONFIGURE_ARGS=	--with-png-dir=${LOCALBASE} --with-gif-dir=${LOCALBASE}

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PORTDOCS=	readme.txt
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/sample/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${CP} -R ${WRKDIR}/${DISTNAME}/www/ ${STAGEDIR}${WWWDIR}

x-generate-plist: stage
	${FIND} ${STAGEDIR}${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${STAGEDIR}${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${STAGEDIR}${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${STAGEDIR}${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.mk>

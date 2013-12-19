# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swfed
PORTVERSION=	0.61
CATEGORIES=	graphics www
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	${PORTNAME}/60035
PKGNAMEPREFIX=	php5-

MAINTAINER=	yoya@awm.jp
COMMENT=	A PHP extension to edit SWF file

LICENSE=	PHP301

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	gif:${PORTSDIR}/graphics/giflib \
		png15:${PORTSDIR}/graphics/png

DEFAULT_PHP_VER=	5
USE_PHP=	zlib
USE_PHPEXT=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/src
CONFIGURE_ARGS=	--with-png-dir=${LOCALBASE} --with-gif-dir=${LOCALBASE}

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

PORTDOCS=	readme.txt
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/sample/${PORTEXAMPLES} ${STAGEDIR}${EXAMPLESDIR}
.endif
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	@${CP} -R ${WRKDIR}/${DISTNAME}/www/ ${STAGEDIR}${WWWDIR}

x-generate-plist: stage
	${FIND} ${STAGEDIR}${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${STAGEDIR}${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${STAGEDIR}${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${STAGEDIR}${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.mk>

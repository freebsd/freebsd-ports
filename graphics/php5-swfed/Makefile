# Created by: TAKATSU Tomonari <tota@FreeBSD.org>
# $FreeBSD$

PORTNAME=	swfed
PORTVERSION=	0.60
CATEGORIES=	graphics www
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	${PORTNAME}/58104
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${PORTDOCS} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/sample/${PORTEXAMPLES} ${EXAMPLESDIR}
.endif
	@${MKDIR} ${WWWDIR}
	@${CP} -R ${WRKDIR}/${DISTNAME}/www/ ${WWWDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${WWWDIR}

x-generate-plist:
	${FIND} ${WWWDIR} -type f | ${SORT} | ${SED} -e 's,${WWWDIR},%%WWWDIR%%,g' > pkg-plist.new
	${FIND} ${WWWDIR} -type d -depth | ${SORT} -r | ${SED} -e 's,${WWWDIR},@dirrm %%WWWDIR%%,g' >> pkg-plist.new
	${ECHO} '@exec chown -R %%WWWOWN%%:%%WWWGRP%% %D/%%WWWDIR%%' >> pkg-plist.new

.include <bsd.port.mk>

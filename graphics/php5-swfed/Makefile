# New ports collection makefile for:	php5-swfed
# Date created:		2010-06-13
# Whom:			TAKATSU Tomonari <tota@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	swfed
PORTVERSION=	0.47
CATEGORIES=	graphics www
MASTER_SITES=	SFJP
MASTER_SITE_SUBDIR=	${PORTNAME}/53540
PKGNAMEPREFIX=	php5-

MAINTAINER=	yoya@awm.jp
COMMENT=	A PHP extension to edit SWF file

BUILD_DEPENDS=	re2c:${PORTSDIR}/devel/re2c
LIB_DEPENDS=	gif.5:${PORTSDIR}/graphics/giflib \
		png.6:${PORTSDIR}/graphics/png

DEFAULT_PHP_VER=	5
IGNORE_WITH_PHP=	4
USE_PHP=	zlib
USE_PHPEXT=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/src
CONFIGURE_ARGS=	--with-zlib-dir=yes

PORTDOCS=	readme.txt
PORTEXAMPLES=	*

PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/doc/${PORTDOCS} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
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

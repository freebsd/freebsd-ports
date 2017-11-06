# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	beautifyphp
PORTVERSION=	0.5.0
PORTREVISION=	1
CATEGORIES=	devel www pear
MASTER_SITES=	SF
DISTNAME=	beautify_php_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR beautifier for PHP4

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:devel/pear

USES=		shebangfix
SHEBANG_FILES=	beautify_php
NO_BUILD=	yes
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/beautify_php \
		share/${PORTNAME}/beautify_php.php \
		share/pear/beautify_php.class.inc

post-patch:
	@${REINPLACE_CMD} 's,/usr/local,${LOCALBASE},g' ${WRKSRC}/beautify_php

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/beautify_php ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/beautify_php.php ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/pear
	${INSTALL_DATA} ${WRKSRC}/beautify_php.class.inc ${STAGEDIR}${PREFIX}/share/pear

.include <bsd.port.mk>

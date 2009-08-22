# New ports collection makefile for:	beautifyphp
# Date created:				03 August 2005
# Whom:	      				Yen-Ming Lee <leeym@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	beautifyphp
PORTVERSION=	0.5.0
CATEGORIES=	devel www pear
MASTER_SITES=	SF
DISTNAME=	beautify_php_${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	PEAR beautifier for PHP4

RUN_DEPENDS=	${LOCALBASE}/share/pear/System.php:${PORTSDIR}/devel/pear

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/beautify_php share/${PORTNAME}/beautify_php.php \
		share/pear/beautify_php.class.inc
PLIST_DIRS=	share/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's,/usr/bin/php,${LOCALBASE}/bin/php,g' ${WRKSRC}/beautify_php
	@${FIND} ${WRKSRC} -name "*.bak" -or -name "*.orig" -delete

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/beautify_php ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/beautify_php.php ${DATADIR}
	@${MKDIR} ${PREFIX}/share/pear
	${INSTALL_DATA} ${WRKSRC}/beautify_php.class.inc ${PREFIX}/share/pear

.include <bsd.port.mk>

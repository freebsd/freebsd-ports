# Created by: Eygene Ryabinkin <rea-fbsd@codelabs.ru>
# $FreeBSD$

PORTNAME=	geshi
PORTVERSION=	1.0.8.2
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GeSHi%20${PORTVERSION}
PKGNAMEPREFIX=	php5-
DISTNAME=	GeSHi-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Native PHP syntax highlighting engine

LICENSE=	GPLv2

NO_BUILD=	yes
USE_PHP=	yes
USES=		tar:bzip2

WRKSRC=		${WRKDIR}/geshi

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/geshi/
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/php/geshi/ ${STAGEDIR}${PREFIX}/lib/php/geshi
	${INSTALL_DATA} ${WRKSRC}/geshi.php ${STAGEDIR}${PREFIX}/lib/php/geshi/
	cd ${WRKSRC}/ && ${COPYTREE_SHARE} geshi ${STAGEDIR}${PREFIX}/lib/php/geshi/
	${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/docs/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	cd ${WRKSRC}/contrib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>

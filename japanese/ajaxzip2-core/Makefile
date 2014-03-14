# $FreeBSD$

PORTNAME=	ajaxzip2
PORTVERSION=	20081102
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kuriyama
PKGNAMESUFFIX=	-core
DISTNAME=	${PORTNAME}-${PORTVERSION}${PKGNAMESUFFIX}

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	ajaxzip2 (Japanese ZIP code utility) core scripts

USES=		dos2unix shebangfix zip
WRKSRC=		${WRKDIR}/${PORTNAME}
NO_BUILD=	YES
SHEBANG_FILES=	work/csv2jsonzip.pl

NO_STAGE=	yes
do-install:
	${MKDIR} ${WWWDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/ajaxzip2.js ${WWWDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/work/csv2jsonzip.pl ${DATADIR}/

.include <bsd.port.mk>

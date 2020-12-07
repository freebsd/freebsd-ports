# Created by: Mahdi Mokhtari <mokhi64@gmail.com>
# $FreeBSD$

PORTNAME=	mari0
PORTVERSION=	1.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://stabyourself.net/dl.php?file=${PORTNAME}-${PORTVERSION:C/\./00/}/
DISTNAME=	${PORTNAME}-source
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Nintendo\'s Super Mario Bros and Valve\'s Portal at same time

LICENSE=	CC-BY-NC-SA-3.0

RUN_DEPENDS=	love08:devel/love08

USES=		zip
NO_BUILD=	yes
NO_ARCH=	yes

SUB_FILES=	mari0
SUB_LIST+=	PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION}

PLIST_FILES=	bin/mari0
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKDIR}/${PORTNAME}_${PORTVERSION}.love \
		${STAGEDIR}${DATADIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/readme.txt ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>

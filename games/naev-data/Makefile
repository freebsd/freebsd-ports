# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	naev
PORTVERSION=	0.6.1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-${PORTVERSION}/
PKGNAMESUFFIX=	-data
DISTNAME=	ndata-${PORTVERSION}
EXTRACT_ONLY=	# empty

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Naev game data file

LICENSE=	GPLv2 GPLv3 CC-BY-3.0 CC-BY-SA-3.0 PD
LICENSE_COMB=	multi

USES=		zip
NO_ARCH=	yes
NO_BUILD=	yes

PORTDATA=	*

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DISTFILES} ${STAGEDIR}${DATADIR}/

.include <bsd.port.mk>

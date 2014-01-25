# Created by: geniusj@ods.org
# $FreeBSD$

PORTNAME=	updatedd
PORTVERSION=	2.6
CATEGORIES=	dns
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	geniusj@ods.org
COMMENT=	Dynamic DNS Update Client supporting multiple services

OPTIONS_DEFINE=	DOCS

USES=		gmake perl5
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

DOCS_EXTRA_PATCHES+=	${PATCHDIR}/extrapatch-disable-portdocs

.include <bsd.port.mk>

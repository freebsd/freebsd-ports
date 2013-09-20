# Created by: David Holm <david@realityrift.com>
# $FreeBSD$

PORTNAME=	adabooch-doc
PORTVERSION=	20030309
CATEGORIES=	devel
MASTER_SITES=	http://www.adapower.net/booch/download/
DISTNAME=	bc-html-${PORTVERSION}
EXTRACT_SUFX=	.zip

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	Manual for adabooch

LICENSE=	GPLv2

USE_ZIP=	yes
NO_BUILD=	yes
NO_MTREE=	yes
WRKSRC=		${WRKDIR}/adabooch-doc-html
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

NO_STAGE=	yes
pre-extract:
	@${MKDIR} ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/share/doc/adabooch/html
	@(cd ${WRKSRC} && ${PAX} -r -w * ${PREFIX}/share/doc/adabooch/html)

.include <bsd.port.mk>

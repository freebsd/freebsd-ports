# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	etl
PORTVERSION=	0.04.18
CATEGORIES=	devel lang
MASTER_SITES=	SF/synfig/releases/${SYNFIG_VERSION}/source/
DISTNAME=	ETL-${PORTVERSION}

MAINTAINER=	woodsb02@gmail.com
COMMENT=	Voria Extended Class and Template Library

WRKSRC=		${WRKDIR}/${DISTNAME}

OPTIONS_DEFINE=	DOCS

SYNFIG_VERSION=	1.0

USES=	gmake pathfix pkgconfig
GNU_CONFIGURE=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

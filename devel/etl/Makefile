# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	etl
PORTVERSION=	0.04.17
CATEGORIES=	devel lang
MASTER_SITES=	SF/synfig/releases/${SYNFIG_VERSION}/source/
DISTNAME=	ETL-${PORTVERSION}

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	Voria Extended Class and Template Library

SYNFIG_VERSION=	0.64.1

USES=	pathfix pkgconfig
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

NO_STAGE=	yes

.include <bsd.port.pre.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for doc in AUTHORS ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

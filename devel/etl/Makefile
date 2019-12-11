# Created by: Yinghong Liu <relaxbsd@gmail.com>
# $FreeBSD$

PORTNAME=	etl
PORTVERSION=	1.2.2
DISTVERSIONPREFIX=v
CATEGORIES=	devel lang

MAINTAINER=	woodsb02@FreeBSD.org
COMMENT=	Voria Extended Class and Template Library

LICENSE=	GPLv2+

NO_ARCH=	yes
PORTSCOUT=	limitw:1,even

USES=		autoreconf pathfix pkgconfig
GNU_CONFIGURE=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	synfig
GH_PROJECT=	synfig
WRKSRC_SUBDIR=	ETL

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for doc in AUTHORS NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

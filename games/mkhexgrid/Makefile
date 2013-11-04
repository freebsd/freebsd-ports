# Created by: aaron@FreeBSD.org
# $FreeBSD$

PORTNAME=	mkhexgrid
PORTVERSION=	0.1.1
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	http://www.nomic.net/~uckelman/mkhexgrid/releases/ \
		http://aaron.daltons.ca/freebsd/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully-configurable hex grid generator

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/lexical_cast.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	libgd.so:${PORTSDIR}/graphics/gd

USES=		gmake

PORTDOCS=	mkhexgrid.html
PLIST_FILES=	bin/mkhexgrid

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mkhexgrid ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/mkhexgrid.html ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

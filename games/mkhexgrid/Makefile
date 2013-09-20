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
COMMENT=	A fully-configurable hex grid generator

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/boost/lexical_cast.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	gd:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes

PORTDOCS=	mkhexgrid.html
PLIST_FILES=	bin/mkhexgrid

NO_STAGE=	yes
do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkhexgrid ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/doc/mkhexgrid.html ${DOCSDIR}
	@${ECHO} "Documentation has been installed into ${DOCSDIR}."
.endif

.include <bsd.port.mk>

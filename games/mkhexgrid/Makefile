# New ports collection makefile for:    mkhexgrid
# Date created:         		29 Dec 2006
# Whom:                 		aaron@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	mkhexgrid
PORTVERSION=	0.1.0
CATEGORIES=	games
MASTER_SITES=	http://www.nomic.net/~uckelman/mkhexgrid/releases/ \
		http://aaron.daltons.ca/freebsd/
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A fully-configurable hex grid generator

BUILD_DEPENDS=	${LOCALBASE}/include/boost/lexical_cast.hpp:${PORTSDIR}/devel/boost
LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd

USE_GMAKE=	yes

PORTDOCS=	mkhexgrid.html
PLIST_FILES=	bin/mkhexgrid

post-patch:
	@${REINPLACE_CMD} -e 's:^LDFLAGS=:LDFLAGS=-L${LOCALBASE}/lib :' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's:^CPPFLAGS=:CPPFLAGS=-I${LOCALBASE}/include :' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/mkhexgrid ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/mkhexgrid.html ${DOCSDIR}
	@${ECHO} "Documentation has been installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>

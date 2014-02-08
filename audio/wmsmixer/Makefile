# Created by: Konstantinos Konstantinidis <kkonstan@daemon.gr>
# $FreeBSD$

PORTNAME=	wmsmixer
PORTVERSION=	0.5.1
PORTREVISION=	1
CATEGORIES=	audio windowmaker
MASTER_SITES=	http://redundancy.redundancy.org/mirror/

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Audio mixer for the WindowMaker dock

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	bin/wmsmixer
PORTDOCS=	README

USES=		imake
USE_XORG=	xpm
MAKE_ARGS=	CC="${CXX}" CFLAGS="${CXXFLAGS}"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wmsmixer ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

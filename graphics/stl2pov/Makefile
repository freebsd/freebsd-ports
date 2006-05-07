# New ports collection makefile for:	stl2pov
# Date created:				9 May 2005
# Whom:					rsmith@xs4all.nl
#
# $FreeBSD$

PORTNAME=	stl2pov
PORTVERSION=	2.2.1
CATEGORIES=	graphics
MASTER_SITES=	http://www.xs4all.nl/~rsmith/software/

MAINTAINER=	rsmith@xs4all.nl
COMMENT=	Converts STL models to POV-Ray meshes

PLIST_FILES=	bin/stl2pov

MAN1=		stl2pov.1
MANCOMPRESSED=	yes

.if defined(NOPORTDOCS)
MAKE_ENV=	NOPORTDOCS=yes
.else
PORTDOCS=	LICENSE README INSTALL
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pipe||; s|-fmerge-constants||; s|--fast-math||' \
		 ${WRKSRC}/Makefile

.include <bsd.port.mk>

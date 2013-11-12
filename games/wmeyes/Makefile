# Created by: Zenin <zenin@archive.rhps.org>
# $FreeBSD$

PORTNAME=	wmeyes
PORTVERSION=	1.2
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.bstern.org/wmeyes/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	World\'s most useless WindowMaker dock app

USES=		imake
USE_XORG=	xpm xmu
NO_INSTALL_MANPAGES=	yes

PORTDOCS=	README
PLIST_FILES=	bin/wmeyes

post-patch:
	@${REINPLACE_CMD} -e 's|Target(|TargetNoMan(|g' ${WRKSRC}/Imakefile

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

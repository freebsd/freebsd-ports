# Created by: Matt Braithwaite <mab@red-bean.com>
# $FreeBSD$

PORTNAME=	xwrits
PORTVERSION=	2.26
PORTREVISION=	2
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lcdf.org/${PORTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Reminds you to take wrist breaks

LICENSE=	GPLv2 # only

GNU_CONFIGURE=	yes
USES=		xorg
USE_XORG=	ice sm x11 xau xdmcp xext xinerama

PLIST_FILES=	bin/xwrits \
		man/man1/xwrits.1.gz

PORTDOCS=	GESTURES NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

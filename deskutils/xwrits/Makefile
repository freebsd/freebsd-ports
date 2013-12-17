# Created by: Matt Braithwaite <mab@red-bean.com>
# $FreeBSD$

PORTNAME=	xwrits
PORTVERSION=	2.26
CATEGORIES=	deskutils
MASTER_SITES=	http://www.lcdf.org/${PORTNAME}/

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Reminds you to take wrist breaks

LICENSE=	GPLv2

GNU_CONFIGURE=	yes

USE_XORG=	ice sm x11 xau xdmcp xext xinerama

PLIST_FILES=	bin/xwrits \
		man/man1/xwrits.1.gz

PORTDOCS=	GESTURES NEWS README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

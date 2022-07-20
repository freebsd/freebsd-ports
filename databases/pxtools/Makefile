PORTNAME=	pxtools
PORTVERSION=	0.0.20
PORTREVISION=	4
CATEGORIES=	databases
MASTER_SITES=	http://jan.kneschke.de/downloads/pxtools/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Collection of tools to work with Paradox databases

LICENSE=	GPLv2

USES=		gettext localbase
GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	Y2K
Y2K_DESC=	Y2k workaround for Paradox < 7.0

Y2K_CONFIGURE_ON=	--enable-y2k

post-patch:
	@${REINPLACE_CMD} -e 's,void \*ptr,int ptr,' \
		${WRKSRC}/src/pxparse.c

.include <bsd.port.mk>

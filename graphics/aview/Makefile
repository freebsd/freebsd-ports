PORTNAME=	aview
DISTVERSION=	1.3.0rc1
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF/aa-project/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Graphics viewer for viewing netpbm format on console or X using aalib
WWW=		http://aa-project.sourceforge.net/aview/

RUN_DEPENDS=	anytopnm:graphics/netpbm
LIB_DEPENDS=	libaa.so:graphics/aalib

USES=		magick:6,run

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:R}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x=no

post-patch:
	@${REINPLACE_CMD} -e 's|/bash|/sh|g' ${WRKSRC}/asciiview
	@${FIND} ${WRKSRC} -name '*.[ch]' | ${XARGS} ${REINPLACE_CMD} -e \
		's|<malloc.h>|<stdlib.h>|g'

.include <bsd.port.mk>

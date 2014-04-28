# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Maaate
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	saper@saper.info
COMMENT=	MPEG audio analysis toolkit

LICENSE=	GPLv2

USES=		gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	API.html ChangeLog THANKS applications.html

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g ; \
		 s|(CCLD|(CXXLD|g' ${WRKSRC}/demos/Makefile.in

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so.1.* ${STAGEDIR}${PREFIX}/lib/Maaate/*.so.1.*

.include <bsd.port.mk>

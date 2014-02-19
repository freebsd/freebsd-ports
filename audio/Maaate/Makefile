# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Maaate
PORTVERSION=	0.3.1
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME:L}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	saper@saper.info
COMMENT=	MPEG audio analysis toolkit

LICENSE=	GPLv2

USES=		gmake
USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

PORTDOCS=	API.html ChangeLog THANKS applications.html

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g ; \
		 s|(CCLD|(CXXLD|g' ${WRKSRC}/demos/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

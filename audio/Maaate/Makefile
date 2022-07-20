PORTNAME=	Maaate
PORTVERSION=	0.3.1
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME:tl}/${PORTNAME}-${PORTVERSION}.tar.gz

MAINTAINER=	saper@saper.info
COMMENT=	MPEG audio analysis toolkit

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		gmake libtool
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

.include <bsd.port.mk>

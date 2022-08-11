PORTNAME=	flite
PORTVERSION=	2.1
CATEGORIES=	audio
MASTER_SITES=	http://www.festvox.org/flite/packed/${PORTNAME}-2.1/
DISTNAME=	${PORTNAME}-${PORTVERSION:}-release

MAINTAINER=	sobomax@FreeBSD.org
COMMENT=	Small run-time speech synthesis engine

LICENSE=	BSD4CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe desthack gmake tar:bzip2

CPE_VENDOR=	cmu
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's|-pd|-pR|g' ${WRKSRC}/main/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

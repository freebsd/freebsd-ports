# Created by: ijliao
# $FreeBSD$

PORTNAME=	dact
PORTVERSION=	0.8.42
CATEGORIES=	archivers
MASTER_SITES=	http://www.rkeene.org/files/oss/dact/release/

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Dynamic Adaptive Compression Tool

LIB_DEPENDS=	libmcrypt.so:${PORTSDIR}/security/libmcrypt \
		liblzo2.so:${PORTSDIR}/archivers/lzo2

USES=		gmake desthack
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	TOBUILD="dact libdact.so dact.conf"

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/dact.conf ${STAGEDIR}${EXAMPLESDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/dact.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

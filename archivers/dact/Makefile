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

NO_STAGE=	yes
USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--libdir=${PREFIX}/lib
CPPFLAGS+=	${CXXFLAGS} -I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ARGS=	TOBUILD="dact libdact.so dact.conf"

MAN1=		dact.1
USE_LDCONFIG=	yes

.include <bsd.port.options.mk>
post-patch:
	@${REINPLACE_CMD} -e "s|prefix = @prefix@|prefix = ${PREFIX}|" \
	-e "s|libdir = @libdir@|libdir = ${PREFIX}/lib|" \
		${WRKSRC}/Makefile.in

pre-install:
	@${RM} -f ${WRKSRC}/libdact.a

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -n ${WRKSRC}/dact.conf ${EXAMPLESDIR} || ${TRUE}
.endif
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Docs/dact.txt ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

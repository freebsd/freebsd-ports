# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezbounce
PORTVERSION=	1.99.15
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	http://www.linuxftw.com/ezbounce/files/

MAINTAINER=	bdrewery@FreeBSD.org
COMMENT=	Highly configurable IRC Proxy

OPTIONS_DEFINE=	DOCS SSL COMPRESS
OPTIONS_DEFAULT=SSL COMPRESS
OPTIONS_SUB=	yes

SSL_USE=		OPENSSL=YES
SSL_CONFIGURE_WITH=	ssl
COMPRESS_BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:${PORTSDIR}/devel/boost-libs
COMPRESS_CONFIGURE_WITH=boost
COMPRESS_DESC=		Chat log compression (requires boost)

GNU_CONFIGURE=	yes
USES=		gmake
USE_GCC=	any

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

post-patch:
	@${SED} -e "s:/path/to:${PREFIX}/sbin:" ${WRKSRC}/sample.conf > \
		${WRKSRC}/ezb.conf.default
	@${REINPLACE_CMD} -e 's|=-O2|="$$CXXFLAGS"|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/ezb.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN}	${WRKSRC}/docs/ezbounce.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/worklog ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>

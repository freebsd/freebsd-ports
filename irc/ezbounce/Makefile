# Created by: Chris Piazza <cpiazza@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ezbounce
PORTVERSION=	1.99.15
PORTREVISION=	7
CATEGORIES=	irc
MASTER_SITES=	http://BSDforge.com/projects/source/irc/ezbounce/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Highly configurable IRC Proxy

OPTIONS_DEFINE=	DOCS SSL COMPRESS
OPTIONS_DEFAULT=SSL COMPRESS
OPTIONS_SUB=	yes

SSL_USES=		ssl
SSL_CONFIGURE_WITH=	ssl
COMPRESS_BUILD_DEPENDS=	${LOCALBASE}/include/boost/function.hpp:devel/boost-libs
COMPRESS_CONFIGURE_WITH=boost
COMPRESS_DESC=		Chat log compression (requires boost)

GNU_CONFIGURE=	yes
USES=		gmake
USE_GCC=	any

# ezbounce 1.99.15 isn't compatible with C++11 and later, which some compilers
# such as GCC 6 default to.
USE_CXXSTD=	gnu++03

SUB_FILES=	pkg-message

post-patch:
	@${SED} -e "s:/path/to:${PREFIX}/sbin:" ${WRKSRC}/sample.conf > \
		${WRKSRC}/ezb.conf.default
	@${REINPLACE_CMD} -e 's|=-O2|="$$CXXFLAGS"|g' ${WRKSRC}/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ezbounce ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ezb.conf.default ${STAGEDIR}${PREFIX}/etc
	${INSTALL_MAN}	${WRKSRC}/docs/ezbounce.1 ${STAGEDIR}${PREFIX}/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/worklog ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

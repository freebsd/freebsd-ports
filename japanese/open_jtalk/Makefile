PORTNAME=	open_jtalk
PORTVERSION=	1.11
CATEGORIES=	japanese audio
MASTER_SITES=	SOURCEFORGE
MASTER_SITE_SUBDIR=	open-jtalk/Open%20JTalk/open_jtalk-${PORTVERSION}
PKGNAMEPREFIX=	ja-

MAINTAINER=	kozos@kozos.jp
COMMENT=	Japanese Text-to-speech system using HTS-engine and Mecab
WWW=		http://open-jtalk.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${PREFIX}/include/iconv.h:converters/libiconv \
		${PREFIX}/lib/libHTSEngine.a:audio/hts_engine-API

USE_CXXSTD=	c++14

HAS_CONFIGURE=	yes

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS   ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING   ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/INSTALL   ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/NEWS      ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README    ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

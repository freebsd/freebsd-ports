PORTNAME=	bencodetools
PORTVERSION=	1.0.1
CATEGORIES=	devel

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Collection of tools for manipulating bencoded data
WWW=		https://gitlab.com/heikkiorsila/bencodetools

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bash:shells/bash

USES=		shebangfix
USE_GITLAB=	yes
GL_ACCOUNT=	heikkiorsila
GL_TAGNAME=	3b28b62e1815d817cb39d609902f99c551aaa9dc
USE_LDCONFIG=	yes

SHEBANG_FILES=	configure

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--c-compiler=${CC} \
		--package-prefix=${STAGEDIR} \
		--prefix=${PREFIX} \
		--without-python

PLIST_FILES=	bin/bencat \
		include/bencodetools/bencode.h \
		lib/libbencodetools.so

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/bencat \
		${STAGEDIR}${PREFIX}/lib/libbencodetools.so

.include <bsd.port.mk>

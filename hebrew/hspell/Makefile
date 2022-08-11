PORTNAME=	hspell
PORTVERSION=	1.4
CATEGORIES=	hebrew
MASTER_SITES=	http://hspell.ivrix.org.il/

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	pmerge multispell
USE_LDCONFIG=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--enable-fatverb \
		--enable-shared

SUB_FILES=	pkg-message

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhspell.so

.include <bsd.port.mk>

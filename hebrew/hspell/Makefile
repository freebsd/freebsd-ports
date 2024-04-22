PORTNAME=	hspell
PORTVERSION=	1.4
PORTREVISION=	1
CATEGORIES=	hebrew
MASTER_SITES=	http://hspell.ivrix.org.il/

MAINTAINER=	onatan@gmail.com
COMMENT=	Hebrew spellchecker and morphology engine
WWW=		http://hspell.ivrix.org.il

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake perl5 shebangfix
SHEBANG_FILES=	pmerge multispell
USE_LDCONFIG=	yes
USE_PERL5=	build
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CFLAGS+=	-fPIC
CONFIGURE_ARGS=	--enable-fatverb \
		--enable-shared

SUB_FILES=	pkg-message

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libhspell.so

.include <bsd.port.mk>

PORTNAME=	recode
PORTVERSION=	3.6
DISTVERSIONPREFIX=	v
PORTREVISION=	15
CATEGORIES=	converters

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Converts files between character sets and usages

LICENSE=	GPLv2+

USES=		gettext iconv libtool makeinfo perl5

USE_GITHUB=	yes
GH_ACCOUNT=	pinard
GH_PROJECT=	Recode

USE_LDCONFIG=	yes
USE_PERL5=	run build

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--without-included-gettext
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

INFO=		recode

post-extract:
	@${CP} ${FILESDIR}/ru.po ${WRKSRC}/i18n
	@${RM} ${WRKSRC}/doc/${PORTNAME}.info*

post-patch:
	@${REINPLACE_CMD} -E \
		'/Project-Id-Version/ { \
			s/3\.[45](r|\.[0-9])?/3.6/; \
			s/: (Free )?recode/: GNU recode/; }' \
		${WRKSRC}/i18n/*.po
	@${REINPLACE_CMD} 's,"iconv\.h","${ICONV_PREFIX}/include/iconv.h",' \
		${WRKSRC}/src/libiconv.c
	@${CP} ${WRKSRC}/lib/error.c ${WRKSRC}/src

# to enable, remove this line and the leading @: from the STRIP_CMD line
post-install:
	@: ${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/librecode.so.*.*.*

.include <bsd.port.mk>

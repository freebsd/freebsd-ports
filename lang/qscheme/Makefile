PORTNAME=	qscheme
PORTVERSION=	0.5.1
PORTREVISION=	10
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.sof.ch/dan/qscheme/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast Scheme interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	libavcall.so:devel/libffcall \
		libgmp.so:math/gmp \
		libpcre.so:devel/pcre

USES=		gmake localbase perl5 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	mkoptable
GNU_CONFIGURE=	yes

CFLAGS+=	-fPIC
MAKE_ARGS=	PCRE_LIB="-L${LOCALBASE}/lib -lpcre"

PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread| ; \
		 /SCM_DEFAULT_LIB_PATH/s|$$datadir|$$prefix/lib|' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qscheme/*/*.so

.include <bsd.port.mk>

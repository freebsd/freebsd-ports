PORTNAME=	qscheme
PORTVERSION=	0.5.1
PORTREVISION=	10
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.sof.ch/dan/qscheme/files/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Small and fast Scheme interpreter
WWW=		https://www.sof.ch/dan/qscheme/index-e.html

LICENSE=	GPLv2

DEPRECATED=	Unmaintained and there are more modern alternatives
EXPIRATION_DATE=2024-04-10

LIB_DEPENDS=	libavcall.so:devel/libffcall \
		libgmp.so:math/gmp \
		libpcre.so:devel/pcre

USES=		gmake localbase perl5 shebangfix
USE_PERL5=	build

SHEBANG_FILES=	mkoptable

GNU_CONFIGURE=	yes

MAKE_ARGS=	PCRE_LIB="-L${LOCALBASE}/lib -lpcre"

CFLAGS+=	-fPIC

PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread| ; \
		 /SCM_DEFAULT_LIB_PATH/s|$$datadir|$$prefix/lib|' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qscheme/*/*.so

.include <bsd.port.mk>

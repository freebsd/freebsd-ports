# Created by: erik@smluc.org
# $FreeBSD$

PORTNAME=	qscheme
PORTVERSION=	0.5.1
PORTREVISION=	8
CATEGORIES=	lang scheme
MASTER_SITES=	http://www.sof.ch/dan/qscheme/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small and fast Scheme interpreter

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libavcall.a:devel/ffcall \
		${LOCALBASE}/lib/libpcre.a:devel/pcre \
		${LOCALBASE}/lib/libgmp.a:math/gmp
LIB_DEPENDS=	libgetline.so:devel/libgetline

USES=		gmake perl5 shebangfix
USE_PERL5=	build
SHEBANG_FILES=	mkoptable
USE_GCC=	any
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pcre-dir=${LOCALBASE}/lib \
		--with-pcre-inc=${LOCALBASE}/include \
		--with-avcall-dir=${LOCALBASE}/lib \
		--with-avcall-inc=${LOCALBASE}/include \
		--with-gmp-dir=${LOCALBASE}/lib \
		--with-gmp-inc=${LOCALBASE}/include

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lgetline

PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDOCS=	*

# because it uses static pcre lib, which is compiled without -fPIC.
# pcre problem likely.
BROKEN_amd64=		Does not build on ${ARCH}
BROKEN_sparc64=		Does not build on ${ARCH}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e \
		's|-lpthread|-pthread| ; \
		 /SCM_DEFAULT_LIB_PATH/s|$$datadir|$$prefix/lib|' \
		${WRKSRC}/configure

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/qscheme/*/*.so

.include <bsd.port.mk>

PORTNAME=	swig
PORTVERSION=	4.0.2
CATEGORIES=	devel
MASTER_SITES=	SF/swig/swig/swig-${PORTVERSION}
PKGNAMESUFFIX=	40

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Generate wrappers for calling C/C++ code from other languages
WWW=		https://www.swig.org/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE-GPL

LIB_DEPENDS=	libpcre.so:devel/pcre

USES=		lua:build

ALL_TARGET=	# empty
CFLAGS+=	-fPIC -DPIC
CONFIGURE_ARGS=	--program-suffix=40 \
		--with-lua=${LOCALBASE}/bin/${LUA_CMD} \
		--with-luaincl=${LUA_INCDIR} \
		--with-lualib=${LUA_LIBDIR}
GNU_CONFIGURE=	yes
TEST_TARGET=	check

PLIST_SUB=	PORTVERSION=${PORTVERSION}

PORTSCOUT=	limit:^4\.0\.

post-configure:
	@${REINPLACE_CMD} -e 's#null#&|| true#' ${WRKSRC}/Makefile

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ccache-swig40 ${STAGEDIR}${PREFIX}/bin/swig40

.include <bsd.port.mk>

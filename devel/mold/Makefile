PORTNAME=	mold
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2.1
PORTREVISION=	6
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern Linker
WWW=		https://github.com/rui314/mold

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

# see https://github.com/rui314/mold/issues/456
BROKEN=		broken with FreeBSD strip
NOT_FOR_ARCHS=	armhf armv7 i386

LIB_DEPENDS=	libtbb.so:devel/onetbb \
		libmimalloc.so:devel/mimalloc

USES=		gmake ssl
MAKE_ENV+=	SYSTEM_TBB=1
MAKE_ENV+=	SYSTEM_MIMALLOC=1
MAKE_ENV+=	STRIP_CMD=${STRIP_CMD}
CXXFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_FLAGS+=	"CXXFLAGS=${CXXFLAGS}"
MAKE_FLAGS+=	"LDFLAGS=${LDFLAGS}"

USE_GITHUB=	yes
GH_ACCOUNT=	rui314
PLIST_FILES=	bin/ld.mold \
		bin/ld64.mold \
		bin/mold \
		lib/mold/mold-wrapper.so \
		libexec/mold/ld \
		share/man/man1/mold.1.gz

post-patch:
	${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>

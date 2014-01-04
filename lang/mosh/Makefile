# Created by: Katsuji ISHIKAWA <katsuji.ishikawa@gmail.com>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	GOOGLE_CODE
PKGNAMESUFFIX=	-scheme

MAINTAINER=	mjt@cltn.org
COMMENT=	A Fast R6RS Scheme interpreter

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libonig.so:${PORTSDIR}/devel/oniguruma5

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${PREFIX}/lib
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

CONFLICTS_INSTALL=	mosh-1.[0-9].*

PROJECTHOST=	mosh-scheme
MAN1=	mosh.1 mosh_config.1

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

post-patch:
	${REINPLACE_CMD} 's|mosh-$$PACKAGE_VERSION|mosh|' ${WRKSRC}/configure

x-generate-plist:
	@${ECHO} bin/mosh > pkg-plist.new
	@${ECHO} bin/mosh_config >> pkg-plist.new
	@${ECHO} bin/nmosh >> pkg-plist.new
	@${FIND} ${LOCALBASE}/lib/mosh -type f | ${SORT} | ${SED} 's|${LOCALBASE}/||' >> pkg-plist.new
	@${FIND} ${LOCALBASE}/lib/mosh -type d | ${SORT} -r | ${SED} 's|${LOCALBASE}/|@dirrm |' >> pkg-plist.new

.include <bsd.port.post.mk>

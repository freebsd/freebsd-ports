# New ports collection makefile for:	jamvm
# Date created:				31 March 2008
# Whom:					Bjoern Koenig
#
# $FreeBSD$

PORTNAME=	jamvm
PORTVERSION=	1.5.1
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/JamVM%20${PORTVERSION}

MAINTAINER=	bkoenig@alpha-tierchen.de
COMMENT=	A compact Java virtual machine

RUN_DEPENDS=	${LOCALBASE}/share/classpath/glibj.zip:${PORTSDIR}/java/classpath

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-classpath-install-dir=${LOCALBASE}
USE_GMAKE=	yes

OPTIONS=	FFI "use libffi to call native methods" ON \
		ZIP "turn-on zip support in the bootstrap loader" ON

.include <bsd.port.pre.mk>

.if defined(WITH_FFI)
LIB_DEPENDS+=		ffi:${PORTSDIR}/devel/libffi
CONFIGURE_ARGS+=	--enable-ffi
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} `pkg-config libffi --cflags`" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib"
.endif

.if defined(WITH_ZIP)
BUILD_DEPENDS+=		zip:${PORTSDIR}/archivers/zip
PLIST_SUB+=		WITH_ZIP="" WITHOUT_ZIP="@comment "
.else
CONFIGURE_ARGS+=	--disable-zip
PLIST_SUB+=		WITH_ZIP="@comment " WITHOUT_ZIP=""
.endif

.if ${ARCH} == "sparc64"
BROKEN=		Does not configure on sparc64
.endif

post-extract:
	@${MV} ${WRKSRC}/src/arch/x86_64.h ${WRKSRC}/src/arch/amd64.h
	@${REINPLACE_CMD} -e "s,\(^include_HEADERS = .*\)jni.h\(.*\),\1\2," ${WRKSRC}/src/Makefile.in

post-configure:
	@${MV} ${WRKSRC}/src/os/bsd/x86_64 ${WRKSRC}/src/os/bsd/amd64

.include <bsd.port.post.mk>

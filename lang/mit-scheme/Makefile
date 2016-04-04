# Created by: jmacd@FreeBSD.org
# $FreeBSD$

PORTNAME=	mit-scheme
PORTVERSION=	9.2
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	GNU/mit-scheme/stable.pkg/${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}-${MIT_SCHEME_ARCH}

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	MIT Scheme: includes runtime, compiler, and edwin binaries

LICENSE=	GPLv2

ONLY_FOR_ARCHS=	i386 amd64
GNU_CONFIGURE=	yes
USES=		gmake
WRKSRC=		${WRKDIR}/mit-scheme-${PORTVERSION}/src/

OPTIONS_DEFINE=	GDBM MCRYPT MHASH OPENSSL PGSQL X11
MCRYPT_DESC=	mcrypt library support
MHASH_DESC=	mhash library support

.include <bsd.port.pre.mk>

# TODO implement db4 support
CONFIGURE_ARGS+=--without-db-4

.if ${PORT_OPTIONS:MGDBM}
PLIST_SUB+=	GDBM=""
CONFIGURE_ARGS+=--with-gdbm=${LOCALBASE}
LIB_DEPENDS+=	libgdbm.so:databases/gdbm
.else
PLIST_SUB+=	GDBM="@comment "
CONFIGURE_ARGS+=--without-gdbm
.endif

.if ${PORT_OPTIONS:MMHASH}
PLIST_SUB+=	MHASH=""
CONFIGURE_ARGS+=--with-mhash=${LOCALBASE}
LIB_DEPENDS+=	libmhash.so:security/mhash
.else
PLIST_SUB+=	MHASH="@comment "
CONFIGURE_ARGS+=--without-mhash
.endif

.if ${PORT_OPTIONS:MMCRYPT}
PLIST_SUB+=	MCRYPT=""
CONFIGURE_ARGS+=--with-mcrypt=${LOCALBASE}
LIB_DEPENDS+=	libmcrypt.so:security/libmcrypt
.else
PLIST_SUB+=	MCRYPT="@comment "
CONFIGURE_ARGS+=--without-mcrypt
.endif

.if ${PORT_OPTIONS:MOPENSSL}
PLIST_SUB+=	OPENSSL=""
CONFIGURE_ARGS+=--with-openssl
.else
PLIST_SUB+=	OPENSSL="@comment "
CONFIGURE_ARGS+=--without-openssl
.endif

.if ${PORT_OPTIONS:MPGSQL}
PLIST_SUB+=	POSTGRESQL=""
CONFIGURE_ARGS+=--with-libpq=${LOCALBASE}
USES+=		pgsql
.else
PLIST_SUB+=	POSTGRESQL="@comment "
CONFIGURE_ARGS+=--without-libpq
.endif

.if ${PORT_OPTIONS:MX11}
PLIST_SUB+=	X11=""
CONFIGURE_ARGS+=--with-x
USE_XORG=	x11
.else
PLIST_SUB+=	X11="@comment "
CONFIGURE_ARGS+=--without-x
.endif

.if ${ARCH} == amd64
MIT_SCHEME_ARCH=x86-64
.else
MIT_SCHEME_ARCH=${ARCH}
.endif

PLIST_SUB+=	MIT_SCHEME_ARCH=${MIT_SCHEME_ARCH}

post-build:
	@${FIND} ${WRKDIR} -type d -empty -delete

do-build:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src/microcode && ${MAKE_CMD}

do-install:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src && ${MAKE_CMD} install DESTDIR=${STAGEDIR}
	${INSTALL_MAN} ${WRKDIR}/mit-scheme-${PORTVERSION}/doc/scheme.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.post.mk>

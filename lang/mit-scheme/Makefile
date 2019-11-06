# Created by: jmacd@FreeBSD.org
# $FreeBSD$

PORTNAME=	mit-scheme
PORTVERSION=	9.2
PORTREVISION=	4
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
OPTIONS_SUB=	yes
MCRYPT_DESC=	mcrypt library support
MHASH_DESC=	mhash library support

GDBM_CONFIGURE_ENABLE=		gdbm
MCRYPT_CONFIGURE_ENABLE=	mcrypt
MHASH_CONFIGURE_ENABLE=		mhash
OPENSSL_CONFIGURE_ENABLE=	openssl
PGSQL_CONFIGURE_ENABLE=		pgsql
X11_CONFIGURE_ENABLE=		x11

GDBM_CONFIGURE_WITH=	gdbm=${LOCALBASE}
MCRYPT_CONFIGURE_WITH=	mcrypt=${LOCALBASE}
MHASH_CONFIGURE_WITH=	mhash=${LOCALBASE}
OPENSSL_CONFIGURE_WITH=	openssl
PGSQL_CONFIGURE_WITH=	libpq=${LOCALBASE}
X11_CONFIGURE_WITH=	x

OPENSSL_USES=		ssl
PGSQL_USES=		pgsql
X11_USES=		xorg
X11_USE=		xorg=x11

GDBM_LIB_DEPENDS+=	libgdbm.so:databases/gdbm
MHASH_LIB_DEPENDS+=	libmhash.so:security/mhash
MCRYPT_LIB_DEPENDS+=	libmcrypt.so:security/libmcrypt

.include <bsd.port.pre.mk>

.if ${ARCH} == amd64
MIT_SCHEME_ARCH=x86-64
.else
MIT_SCHEME_ARCH=${ARCH}
.endif

PLIST_SUB+=	MIT_SCHEME_ARCH=${MIT_SCHEME_ARCH}

post-patch:
	@${REINPLACE_CMD} -e 's|-export-dynamic|-rdynamic|g' ${WRKSRC}/microcode/configure ${WRKSRC}/microcode/configure.ac

post-build:
	@${FIND} ${WRKDIR} -type d -empty -delete

do-build:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src/microcode && ${MAKE_CMD}

do-install:
	@cd ${WRKDIR}/mit-scheme-${PORTVERSION}/src && ${MAKE_CMD} install DESTDIR=${STAGEDIR}
	${INSTALL_MAN} ${WRKDIR}/mit-scheme-${PORTVERSION}/doc/scheme.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	[ $$(${LS} ${STAGEDIR}${PREFIX}/lib/mit-scheme-${MIT_SCHEME_ARCH}/lib/ | wc -l) = 0 ] || \
		${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/mit-scheme-${MIT_SCHEME_ARCH}/lib/*.so

.include <bsd.port.post.mk>

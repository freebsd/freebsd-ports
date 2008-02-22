# New ports collection makefile for:	ghc
# Date created:				28 August 1999
# Whom:					Simon Marlow <simonmar@microsoft.com>
#
# $FreeBSD$

PORTNAME=	ghc
PORTVERSION=	6.8.2
CATEGORIES=	lang haskell
MASTER_SITES=	http://www.haskell.org/ghc/dist/${PORTVERSION}/:source \
		http://www.haskell.org/ghc/dist/${PORTVERSION}/FreeBSD/:boot \
		${MASTER_SITE_LOCAL:S/$/:boot/}
DISTFILES=	ghc-${PORTVERSION}-src${EXTRACT_SUFX}:source \
		ghc-${PORTVERSION}-src-extralibs${EXTRACT_SUFX}:source

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A Compiler for the functional language Haskell

ONLY_FOR_ARCHS=	i386 amd64

USE_AUTOTOOLS=	autoconf:261:env
USE_BZIP2=	yes
LIB_DEPENDS+=	gmp.7:${PORTSDIR}/math/libgmp4

USE_PERL5=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

OPTIONS=	PROFILE "Compile for profiling as well" on

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/lib/libreadline.so.5)
LIB_DEPENDS+=	readline.5:${PORTSDIR}/devel/readline
.endif

.if ${ARCH} == "i386"
.if ${OSVERSION} >= 700000
DISTFILES+=	ghc-${PORTVERSION}-i386-unknown-freebsd7-boot${EXTRACT_SUFX}:boot
.elif ${OSVERSION} >= 600000
DISTFILES+=	ghc-${PORTVERSION}-i386-unknown-freebsd6-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported at the moment
.endif
.endif

.if ${ARCH} == "amd64"
.if ${OSVERSION} >= 700000
DISTFILES+=	ghc-${PORTVERSION}-x86_64-unknown-freebsd7-boot${EXTRACT_SUFX}:boot
.else
IGNORE=		unsupported at the moment
.endif
.endif

PLIST_SUB+=	GHC_VERSION=${PORTVERSION}
.if defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFILE="@comment "
.else
PLIST_SUB+=	PROFILE=""
.endif

# This port builds by downloading a minimal binary distribution of GHC and
# using that to bootstrap.
BOOT_DIR=	${WRKDIR}/ghc-${PORTVERSION}-boot
BOOT_GHC=	${BOOT_DIR}/bin/ghc-${PORTVERSION}

CONFIGURE_ARGS+=	--with-ghc=${BOOT_GHC}  --with-gcc=${CC} \
	--with-gmp-includes=${LOCALBASE}/include --with-gmp-libraries=${LOCALBASE}/lib 
# specifying CONFIGURE_TARGET doesn't work for some reason.
CONFIGURE_TARGET=
# libgmp:
CONFIGURE_ENV+=	CFLAGS=-I${LOCALBASE}/include LDFLAGS=-L${LOCALBASE}/lib

# override TMPDIR because /tmp often doesn't have enough space
# to build some of the larger libraries.
TMPDIR=		${WRKSRC}/tmp
MAKE_ENV+=	TMPDIR=${TMPDIR}
EXCLUDELIBS=	ALUT GLUT HGL OpenAL OpenGL X11

post-extract:
.if defined(WITHOUT_PROFILE)
	@${ECHO} >>${WRKSRC}/mk/build.mk GhcLibWays=
.endif
	@cd ${WRKSRC}/libraries && ${RM} -rf ${EXCLUDELIBS}

post-patch:
	@${REINPLACE_CMD} s+%%LOCALBASE%%+${LOCALBASE}+ \
		${WRKSRC}/rts/package.conf.in

pre-configure:
	@(cd ${BOOT_DIR} && ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS} --prefix=${BOOT_DIR})
	@(cd ${BOOT_DIR} && ${GMAKE} install)

pre-build:
	@${MKDIR} ${TMPDIR}

post-install:
	@${MKDIR} ${PREFIX}/lib/ghc-${PORTVERSION}/cabal		# cabalised hs-foo-ghc ports

.include <bsd.port.post.mk>

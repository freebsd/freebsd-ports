# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	3.7a.2
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/indes/fp/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme interpreter and native code compiler

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	gc.1:${PORTSDIR}/devel/boehm-gc \
		gmp.10:${PORTSDIR}/math/gmp

OPTIONS=	ALSA "Enable ALSA support" off \
		FLAC "Enable FLAC support" off \
		GSTREAMER "Enable Gstreamer support" off \
		MPG123 "Enable MPG123 support" off \
		SQLITE "Enable SQLite support" off \
		OPENSSL "Enable OpenSSL support" on

WANT_GSTREAMER=	yes
USE_GCC=	4.5+
USE_EMACS=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${WRKDIR}/fakeroot \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--customgc=no \
		--gclibdir=${LOCALBASE}/lib \
		--gcincdir=${LOCALBASE}/include \
		--emacs=${EMACS_NAME}
ALL_TARGET=	build compile-bee
INSTALL_TARGET=	install-progs install-bee
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/bigloo/${PORTVERSION:R}
PLIST_SUB=	BIGLOO_VERSION="${PORTVERSION:R}"
MAKE_JOBS_UNSAFE=yes

MAN1=		bigloo.1
INFO=		bigloo

.include <bsd.port.options.mk>

.if defined(WITH_ALSA)
LIB_DEPENDS+=	asound.2:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if defined(WITH_FLAC)
LIB_DEPENDS+=	FLAC.10:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=--disable-flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if defined(WITH_GSTREAMER)
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if defined(WITH_MPG123)
LIB_DEPENDS+=	mpg123.0:${PORTSDIR}/audio/mpg123
PLIST_SUB+=	MPG123=""
.else
CONFIGURE_ARGS+=--disable-mpg123
PLIST_SUB+=	MPG123="@comment "
.endif

.if defined(WITH_SQLITE)
USE_SQLITE=	yes
PLIST_SUB+=	SQLITE=""
.else
CONFIGURE_ARGS+=--disable-pkglib --disable-sqlite
PLIST_SUB+=	SQLITE="@comment "
.endif

.if defined(WITH_OPENSSL)
USE_OPENSSL=	yes
PLIST_SUB+=	OPENSSL=""
.else
CONFIGURE_ARGS+=--disable-ssl
PLIST_SUB+=	OPENSSL="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

# SRFI-27 requires a 32bits platform
.if ${ARCH} == "i386"
PLIST_SUB+=	SRFI27=""
.else
CONFIGURE_ARGS+=--disable-srfi27
PLIST_SUB+=	SRFI27="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^coflags=|#coflags=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|"-lthr"|"${PTHREAD_LIBS}"|g' \
		${WRKSRC}/autoconf/pthread
.for i in autoconf/mixer api/multimedia/src/Unix/bglmixer.c
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/${i}
.endfor

post-configure:
	@${FIND} ${WRKSRC} -name "bigloo_config.h" | ${XARGS} \
		${REINPLACE_CMD} -e 's/BGL_HAVE_SENDFILE 1/BGL_HAVE_SENDFILE 0/'

post-install:
	${INSTALL_MAN} ${WRKSRC}/manuals/bigloo.man ${MANPREFIX}/man/man1/${MAN1}
	${INSTALL_DATA} ${WRKSRC}/manuals/bigloo.info ${PREFIX}/${INFO_PATH}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.sui ${DOCSDIR}
.endif

test: build
	@(cd ${WRKSRC}; ${GMAKE} test)

.include <bsd.port.post.mk>

# New ports collection makefile for:    bigloo
# Date created:         15 Jul 2002
# Whom:                 Stanislav Grozev <tacho@daemonz.org>
#
# $FreeBSD$
#

PORTNAME=	bigloo
PORTVERSION=	3.8c
PORTREVISION=	1
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/indes/fp/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Scheme interpreter and native code compiler

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	pcre:${PORTSDIR}/devel/pcre \
		gmp:${PORTSDIR}/math/gmp

OPTIONS_DEFINE=	AVAHI ALSA FLAC GSTREAMER MPG123 SQLITE OPENSSL DOCS
OPTIONS_DEFAULT=OPENSSL
MPG123_DESC=	Enable MPG123 support

USE_GCC=	4.6+
USE_EMACS=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--docdir=${WRKDIR}/fakeroot \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--emacs=${EMACS_NAME} \
		--disable-phidget
ALL_TARGET=	build compile-bee
INSTALL_TARGET=	install-progs install-bee
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/bigloo/${PORTVERSION}
PLIST_SUB=	BIGLOO_VERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=yes

MAN1=		bigloo.1
INFO=		bigloo

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAVAHI}
LIB_DEPENDS+=	avahi-client:${PORTSDIR}/net/avahi-app
PLIST_SUB+=	AVAHI=""
.else
CONFIGURE_ARGS+=--disable-avahi
PLIST_SUB+=	AVAHI="@comment "
.endif

.if ${PORT_OPTIONS:MALSA}
LIB_DEPENDS+=	asound:${PORTSDIR}/audio/alsa-lib
PLIST_SUB+=	ALSA=""
.else
CONFIGURE_ARGS+=--disable-alsa
PLIST_SUB+=	ALSA="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
.if empty(PORT_OPTIONS:MALSA)
IGNORE=		FLAC support requires ALSA
.endif
LIB_DEPENDS+=	FLAC:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=--disable-flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
PLIST_SUB+=	GSTREAMER=""
.else
CONFIGURE_ARGS+=--disable-gstreamer
PLIST_SUB+=	GSTREAMER="@comment "
.endif

.if ${PORT_OPTIONS:MMPG123}
.if empty(PORT_OPTIONS:MALSA)
IGNORE=		MPG123 support requires ALSA
.endif
LIB_DEPENDS+=	mpg123:${PORTSDIR}/audio/mpg123
PLIST_SUB+=	MPG123=""
.else
CONFIGURE_ARGS+=--disable-mpg123
PLIST_SUB+=	MPG123="@comment "
.endif

.if ${PORT_OPTIONS:MSQLITE}
USE_SQLITE=	yes
PLIST_SUB+=	SQLITE=""
.else
CONFIGURE_ARGS+=--disable-pkglib --disable-sqlite
PLIST_SUB+=	SQLITE="@comment "
.endif

.if ${PORT_OPTIONS:MOPENSSL}
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
	@${REINPLACE_CMD} -e '/LDFLAGS=/s|export|true|g' \
		${WRKSRC}/gc/configure-gc-7.3alpha1-20120316
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
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/manuals/*.sui ${DOCSDIR}
.endif

test: build
	@(cd ${WRKSRC}; ${GMAKE} test)

.include <bsd.port.post.mk>

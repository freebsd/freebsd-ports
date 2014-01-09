# Created by: Stanislav Grozev <tacho@daemonz.org>
# $FreeBSD$

PORTNAME=	bigloo
PORTVERSION=	4.0b
CATEGORIES=	lang scheme
MASTER_SITES=	ftp://ftp-sop.inria.fr/indes/fp/Bigloo/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Scheme interpreter and native code compiler

LICENSE=	GPLv2 LGPL20
LICENSE_COMB=	multi

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre \
		libgmp.so:${PORTSDIR}/math/gmp

OPTIONS_DEFINE=	ALSA AVAHI DOCS FLAC GSTREAMER MPG123 OPENSSL SQLITE
OPTIONS_DEFAULT=OPENSSL
OPTIONS_SUB=	yes

USES=		gmake
USE_GCC=	yes
USE_EMACS=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	pcrelib="-L${LOCALBASE}/lib -lpcre" \
		gmplib="-L${LOCALBASE}/lib -lgmp"
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--cflags="${CPPFLAGS}" \
		--coflags="${CFLAGS}" \
		--ldflags="${LDFLAGS}" \
		--docdir="${DOCSDIR}" \
		--lispdir=${LOCALBASE}/${EMACS_SITE_LISPDIR}/bigloo \
		--emacs=${EMACS_NAME} \
		--disable-phidget
ALL_TARGET=	build compile-bee
INSTALL_TARGET=	install-progs install-bee
USE_LDCONFIG=	${PREFIX}/lib ${PREFIX}/lib/bigloo/${PORTVERSION}
PLIST_SUB=	BIGLOO_VERSION="${PORTVERSION}"
MAKE_JOBS_UNSAFE=yes

CPPFLAGS+=	-idirafter ${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		bdb bigloo

ALSA_LIB_DEPENDS=	libasound.so:${PORTSDIR}/audio/alsa-lib
ALSA_CONFIGURE_OFF=	--disable-alsa --disable-wav
AVAHI_LIB_DEPENDS=	libavahi-client.so:${PORTSDIR}/net/avahi-app
AVAHI_CONFIGURE_OFF=	--disable-avahi
FLAC_LIB_DEPENDS=	libFLAC.so:${PORTSDIR}/audio/flac
FLAC_CONFIGURE_OFF=	--disable-flac
GSTREAMER_USE=		GSTREAMER=yes
GSTREAMER_CONFIGURE_OFF=--disable-gstreamer
MPG123_LIB_DEPENDS=	libmpg123.so:${PORTSDIR}/audio/mpg123
MPG123_CONFIGURE_OFF=	--disable-mpg123
OPENSSL_USE=		OPENSSL=yes
OPENSSL_CONFIGURE_OFF=	--disable-ssl
SQLITE_USE=		SQLITE=yes
SQLITE_CONFIGURE_OFF=	--disable-pkglib --disable-sqlite

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|"-lthr"|"-pthread"|g' \
		${WRKSRC}/autoconf/pthread
	@${REINPLACE_CMD} -e 's|machine/soundcard|sys/soundcard|g' \
		${WRKSRC}/autoconf/mixer \
		${WRKSRC}/api/multimedia/src/Unix/bglmixer.c
	@${FIND} ${WRKSRC}/gc -maxdepth 1 -type f | ${XARGS} \
		${REINPLACE_CMD} -e '/LDFLAGS=/s|export|true|g'

post-install:
.for i in bglafile bgldepend bgljfile bglmake bglmco bglpp bglprof bgltags bigloo
	${INSTALL_MAN} ${WRKSRC}/manuals/${i}.man \
		${STAGEDIR}${MANPREFIX}/man/man1/${i}.1
.endfor
	(cd ${WRKSRC}/manuals && ${INSTALL_DATA} bdb.info bigloo.info \
		${STAGEDIR}${PREFIX}/${INFO_PATH})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/manuals && ${INSTALL_DATA} *.html *.sui \
		${STAGEDIR}${DOCSDIR})

test: build
	@(cd ${WRKSRC}; ${MAKE_CMD} test)

.include <bsd.port.post.mk>

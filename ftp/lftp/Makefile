# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	lftp
PORTVERSION=	4.8.4
PORTREVISION=	1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://lftp.tech/ftp/ \
		http://lftp.tech/ftp/old/ \
		http://lftp.cybermirror.org/ \
		http://lftp.cybermirror.org/old/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		http://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Shell-like command line ftp client

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn2.so:dns/libidn2

USES=		charsetfix iconv libtool localbase readline shebangfix
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS BUGS ChangeLog FAQ FEATURES INSTALL \
		MIRRORS NEWS README README.debug-levels README.modules \
		THANKS TODO

SHEBANG_FILES=	src/verify-file \
		src/convert-mozilla-cookies \
		src/xdg-move

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	SSL OPENSSL
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USES=	ssl
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=	pkgconfig

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lftp.conf \
		${STAGEDIR}${PREFIX}/etc/lftp.conf.sample

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.pre.mk>

# Only link to libthr if necessary
.if ${PORT_OPTIONS:MGNUTLS}
NEED_PTHREAD=	yes
.else
.if exists(${OPENSSLLIB}/libssl.so)
NEED_PTHREAD!=	ldd ${OPENSSLLIB}/libssl.so | ${GREP} -w 'libthr\.so' || ${ECHO_CMD}
.else
NEED_PTHREAD=	# empty
.endif
.endif
.if !empty(NEED_PTHREAD)
LDFLAGS+=	-pthread
.endif

.if ${ARCH} == powerpc64
USE_GCC=	yes
.endif

.include <bsd.port.post.mk>

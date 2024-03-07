PORTNAME=	lftp
PORTVERSION=	4.9.2
PORTREVISION=	1
CATEGORIES=	ftp
MASTER_SITES=	ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		http://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		http://lftp.cybermirror.org/ \
		http://lftp.cybermirror.org/old/ \
		http://lftp.tech/ftp/ \
		http://lftp.tech/ftp/old/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Shell-like command-line FTP client
WWW=		https://lftp.tech/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libidn2.so:dns/libidn2

USES=		charsetfix compiler:c++11-lang cpe iconv libtool localbase \
		readline shebangfix
CPE_VENDOR=	lftp_project

SHEBANG_FILES=	src/convert-mozilla-cookies src/verify-file src/xdg-move

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PORTDOCS=	AUTHORS BUGS ChangeLog FAQ FEATURES INSTALL MIRRORS NEWS README \
		README.debug-levels README.modules THANKS TODO

OPTIONS_DEFINE=		DOCS NLS
OPTIONS_DEFAULT=	OPENSSL
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_SUB=		yes

GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=		pkgconfig
GNUTLS_CONFIGURE_WITH=	gnutls
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_USES=		ssl
OPENSSL_CONFIGURE_WITH=	openssl

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

.include <bsd.port.post.mk>

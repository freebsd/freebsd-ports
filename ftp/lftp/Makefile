# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	lftp
PORTVERSION=	4.7.1
CATEGORIES=	ftp ipv6
MASTER_SITES=	http://lftp.yar.ru/ftp/ \
		http://lftp.yar.ru/ftp/old/ \
		http://lftp.cybermirror.org/ \
		http://lftp.cybermirror.org/old/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/ \
		http://ftp.st.ryukoku.ac.jp/pub/network/ftp/lftp/old/ \
		http://ftp.tuwien.ac.at/infosys/browsers/ftp/lftp/ \
		ftp://ftp.cs.tu-berlin.de/pub/net/ftp/lftp/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Shell-like command line ftp client

LICENSE=	GPLv3

LIB_DEPENDS=	libexpat.so:textproc/expat2

USES=		charsetfix iconv libtool localbase readline shebangfix
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	ac_cv_type_max_align_t=yes

PORTDOCS=	AUTHORS BUGS ChangeLog FAQ FEATURES INSTALL \
		MIRRORS NEWS README README.debug-levels README.modules \
		THANKS TODO

SHEBANG_FILES=	src/verify-file \
		src/convert-mozilla-cookies \
		src/xdg-move

OPTIONS_DEFINE=	NLS
OPTIONS_RADIO=	SSL
OPTIONS_RADIO_SSL=	OPENSSL GNUTLS
OPTIONS_DEFAULT=	SSL OPENSSL NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls
OPENSSL_CONFIGURE_WITH=	openssl
OPENSSL_USE=	OPENSSL=yes
GNUTLS_CONFIGURE_WITH=	gnutls
GNUTLS_LIB_DEPENDS=	libgnutls.so:security/gnutls
GNUTLS_USES=	pkgconfig

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
. if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000015
WITH_OPENSSL_PORT=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
. endif
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lftp.conf \
		${STAGEDIR}${PREFIX}/etc/lftp.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	lftp
PORTVERSION=	4.6.0
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

LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2

USES=		charsetfix iconv libtool readline shebangfix

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
# XXX FreeBSD 9.x has posix_fallocate() for OSVERSION > 900035,
# but is missing the required POSIX_FADV_* macros
CONFIGURE_ENV=	i_cv_posix_fallocate_works=no

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
GNUTLS_LIB_DEPENDS=	libgnutls.so:${PORTSDIR}/security/gnutls
GNUTLS_USES=	pkgconfig

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/lftp.conf \
		${STAGEDIR}${PREFIX}/etc/lftp.conf.sample
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

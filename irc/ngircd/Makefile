PORTNAME=	ngircd
DISTVERSION=	27
PORTEPOCH=	1
CATEGORIES=	irc
MASTER_SITES=	https://ngircd.barton.de/pub/ngircd/ \
		https://ngircd.mirror.3rz.de/pub/ngircd/ \
		https://ngircd.sourceforge.io/pub/ngircd/

MAINTAINER=	me@svmhdvn.name
COMMENT=	Free open source daemon for Internet Relay Chat (IRC)
WWW=		https://ngircd.barton.de/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		cpe localbase:ldflags tar:xz
CPE_VENDOR=	barton
CPE_VERSION=	${DISTVERSION:C/^([0-9]+)$/\1.0/}
USE_RC_SUBR=	${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR}

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PORTDOCS=	doc/*

OPTIONS_DEFINE=		DEBUG DOCS ICONV IDENT IPV6 IRCPLUS LIBWRAP PAM \
			SNIFFER SYSLOG ZLIB
OPTIONS_DEFAULT=	ICONV IRCPLUS LIBWRAP OPENSSL PAM SYSLOG ZLIB
OPTIONS_RADIO=		TLS
OPTIONS_RADIO_TLS=	GNUTLS OPENSSL

IDENT_DESC=			IDENT (AUTH) protocol support
IRCPLUS_DESC=			IRC+ protocol
SNIFFER_DESC=			IRC traffic sniffer
DEBUG_CONFIGURE_ENABLE=		debug
GNUTLS_LIB_DEPENDS=		libgnutls.so:security/gnutls
GNUTLS_CONFIGURE_WITH=		gnutls
ICONV_USES=			iconv
ICONV_CONFIGURE_WITH=		iconv
IDENT_LIB_DEPENDS=		libident.so:security/libident
IDENT_CONFIGURE_WITH=		ident
IPV6_CONFIGURE_ENABLE=		ipv6
IRCPLUS_CONFIGURE_ENABLE=	ircplus
LIBWRAP_CONFIGURE_WITH=		tcp-wrappers
OPENSSL_USES=			ssl
OPENSSL_CONFIGURE_WITH=		openssl
PAM_CONFIGURE_WITH=		pam
SNIFFER_CONFIGURE_ENABLE=	sniffer
SYSLOG_CONFIGURE_WITH=		syslog
ZLIB_CONFIGURE_WITH=		zlib

post-patch:
	@${REINPLACE_CMD} -e '/LIBS/s|-liconv|${ICONV_LIB}|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/toplevel/s| \.\./COPYING|| ; \
		 /INSTALL/s|.conf$$|.conf.sample|' ${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} -e \
		's|;ServerGID = 65534$$|ServerGID = ${USERS:[0]}| ; \
		 s|;ServerUID = 65534$$|ServerUID = ${GROUPS:[0]}|' \
		${WRKSRC}/doc/sample-ngircd.conf.tmpl

.include <bsd.port.mk>

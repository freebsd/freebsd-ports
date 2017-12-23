# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	dnscrypt-proxy
PORTVERSION=	1.9.5
PORTREVISION=	3
CATEGORIES=	dns
MASTER_SITES=	https://download.dnscrypt.org/dnscrypt-proxy/ \
		https://download.dnscrypt.org/dnscrypt-proxy/old/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Boost privacy and security of DNS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN_powerpc64=	fails to compile: fpst.c: error: redefinition of typedef 'FPST'

LIB_DEPENDS=	libsodium.so:security/libsodium

USERS=		_dnscrypt-proxy
GROUPS=		_dnscrypt-proxy

GNU_CONFIGURE=	yes
USES=		gmake

INSTALL_TARGET=	install-strip

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README* THANKS

OPTIONS_DEFINE=	DOCS PLUGINS PLUGINS_RELAXED PLUGINS_ROOT
OPTIONS_SINGLE=	RCWHICH
OPTIONS_SINGLE_RCWHICH=	RCSINGLE RCMULTI
OPTIONS_DEFAULT=	PLUGINS RCSINGLE
OPTIONS_SUB=	yes

PLUGINS_RELAXED_DESC=	Allow loading plugins owned by other users
PLUGINS_ROOT_DESC=	Only load plugins sitting in the default plugins directory
RCWHICH_DESC=	Rc script to use:
RCSINGLE_DESC=	Use default rc script for single daemon
RCMULTI_DESC=	Use experimental rc script for multiple instances

PLUGINS_CONFIGURE_ENABLE=	plugins
PLUGINS_LIB_DEPENDS=	libltdl.so:devel/libltdl \
		libldns.so:dns/ldns

PLUGINS_USE=	LDCONFIG=${PREFIX}/lib/dnscrypt-proxy
PLUGINS_USES=	libtool
PLUGINS_RELAXED_CONFIGURE_ENABLE=	relaxed-plugins-permissions
PLUGINS_ROOT_CONFIGURE_ENABLE=	plugins-root

RCSINGLE_VARS=	USE_RC_SUBR=${PORTNAME}
RCSINGLE_SUB_FILES=	pkg-message
RCMULTI_VARS=	USE_RC_SUBR=${PORTNAME}_multi
RCMULTI_SUB_FILES=	pkg-message_multi

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/hostip.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${MV} ${STAGEDIR}${PREFIX}/etc/dnscrypt-proxy.conf ${STAGEDIR}${PREFIX}/etc/dnscrypt-proxy.conf.sample

.include <bsd.port.mk>

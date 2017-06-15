# Created by: David Taylor <davidt@yadt.co.uk>
# $FreeBSD$

PORTNAME=	ircd-hybrid
PORTVERSION=	8.2.21
CATEGORIES=	irc ipv6
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	db@FreeBSD.org
COMMENT=	Fast irc daemon with a number of new features

LICENSE=	GPLv2

INSTALL_IGNORES=	ircu-* ircd-rat* charby*

# :keepla because port uses lt_dlopen
USES=		cpe gmake libtool:keepla tar:tgz
GNU_CONFIGURE=	yes

USERS=		ircd
GROUPS=		${USERS}

USE_RC_SUBR=	ircd-hybrid
SUB_FILES=	pkg-message
PLIST_SUB=	PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	OPENSSL HALFOPS ASSERT
OPTIONS_DEFAULT=OPENSSL

ASSERT_CONFIGURE_ENABLE=	assert
ASSERT_DESC=	Enable parts of the debugging code

HALFOPS_CONFIGURE_ENABLE=	halfops
HALFOPS_DESC=	Enable halfops on the server

OPENSSL_DESC=	Enable openssl - allows use of CHALLENGE and encrypted links

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENSSL}
USES	+=	ssl
CONFIGURE_ARGS+=	--enable-openssl=${OPENSSLBASE}
.endif

CONFIGURE_ARGS+=	\
	--sysconfdir=${PREFIX}/etc/ircd-hybrid \
	--datarootdir=${PREFIX}/share/${PORTNAME}-${PORTVERSION} \
	--localstatedir=/var

.include <bsd.port.mk>

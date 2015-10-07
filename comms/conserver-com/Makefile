# $FreeBSD$

PORTNAME=	conserver
PORTVERSION=	8.2.1
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	http://www.conserver.com/ \
		ftp://ftp.conserver.com/conserver/
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Application that allows multiple users to watch serial consoles

CONFLICTS_INSTALL=	conserver-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-pam --with-libwrap --with-openssl
USE_OPENSSL=	yes
USE_RC_SUBR=	conserver

OPTIONS_DEFINE=	UDS GSSAPI GSSAPIONLY STRIPREALM
UDS_DESC=	Use Unix domain sockets for client/server
STRIPREALM_DESC=Strip @REALM when using GSSAPI
GSSAPIONLY_DESC=Never prompt for a password when using GSSAPI
STRIPREALM_IMPLIES=	GSSAPI
GSSAPIONLY_IMPLIES=	GSSAPI

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

UDS_CONFIGURE_WITH=	uds
GSSAPI_CONFIGURE_WITH=	gssapi
STRIPREALM_CONFIGURE_WITH=	striprealm
GSSAPIONLY_EXTRA_PATCHES=		${FILESDIR}/extra-patch-conserver__master.c

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/conserver-convert

.include <bsd.port.mk>

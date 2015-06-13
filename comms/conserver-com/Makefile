# $FreeBSD$

PORTNAME=	conserver
PORTVERSION=	8.2.1
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

.include <bsd.port.options.mk>

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

.if ${PORT_OPTIONS:MUDS}
CONFIGURE_ARGS+=	--with-uds
.endif

.if ${PORT_OPTIONS:MGSSAPI}
CONFIGURE_ARGS+=	--with-gssapi
.if ${PORT_OPTIONS:MSTRIPREALM}
CONFIGURE_ARGS+=	--with-striprealm
.endif
.if ${PORT_OPTIONS:MGSSAPIONLY}
EXTRA_PATCHES=		${FILESDIR}/extra-patch-conserver__master.c
.endif
.endif

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/conserver-convert

.include <bsd.port.mk>

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

LICENSE=	BSD2CLAUSE

CONFLICTS_INSTALL=	conserver-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-pam --with-libwrap --with-openssl

USE_OPENSSL=	yes
USE_RC_SUBR=	conserver

OPTIONS_DEFINE=	FREEIPMI GSSAPI GSSAPIONLY STRIPREALM UDS
FREEIPMI_DESC=	Compile in FreeIPMI support
GSSAPIONLY_DESC=Never prompt for a password when using GSSAPI
GSSAPIONLY_IMPLIES=	GSSAPI
STRIPREALM_DESC=Strip @REALM when using GSSAPI
STRIPREALM_IMPLIES=	GSSAPI
UDS_DESC=	Use Unix domain sockets for client/server

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

FREEIPMI_CONFIGURE_ON=	--with-freeipmi=${LOCALBASE}
FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
GSSAPI_CONFIGURE_WITH=	gssapi
GSSAPIONLY_EXTRA_PATCHES=		${FILESDIR}/extra-patch-conserver__master.c
STRIPREALM_CONFIGURE_WITH=	striprealm
UDS_CONFIGURE_WITH=	uds

post-patch:
	@${REINPLACE_CMD} -e 's,impi,ipmi,' ${WRKSRC}/conserver.cf/conserver.cf.man

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/conserver-convert

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	conserver
DISTVERSIONPREFIX=	v
DISTVERSION=	8.2.4
CATEGORIES=	comms
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Application that allows multiple users to watch serial consoles

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf ssl
USE_GITHUB=	yes
USE_RC_SUBR=	conserver

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-pam --with-libwrap --with-openssl

CONFLICTS_INSTALL=	conserver-[0-9]*

OPTIONS_DEFINE=	FREEIPMI GSSAPI GSSAPIONLY STRIPREALM UDS
FREEIPMI_DESC=	Compile in FreeIPMI support
GSSAPIONLY_DESC=Never prompt for a password when using GSSAPI
GSSAPIONLY_IMPLIES=	GSSAPI
STRIPREALM_DESC=Strip @REALM when using GSSAPI
STRIPREALM_IMPLIES=	GSSAPI
UDS_DESC=	Use Unix domain sockets for client/server

FREEIPMI_CONFIGURE_ON=	--with-freeipmi=${LOCALBASE}
FREEIPMI_LIB_DEPENDS=	libfreeipmi.so:sysutils/freeipmi
GSSAPI_CONFIGURE_WITH=	gssapi
GSSAPIONLY_EXTRA_PATCHES=		${FILESDIR}/extra-patch-conserver__master.c
STRIPREALM_CONFIGURE_WITH=	striprealm
UDS_CONFIGURE_WITH=	uds

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/conserver-convert

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

post-extract:
.for file in config.guess config.sub
	${CP} -f ${TEMPLATES}/${file} ${WRKSRC}
.endfor

.include <bsd.port.mk>

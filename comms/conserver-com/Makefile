# $FreeBSD$

PORTNAME=	conserver
PORTVERSION=	8.1.18
CATEGORIES=	comms
MASTER_SITES=	http://www.conserver.com/ \
		ftp://ftp.conserver.com/conserver/
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Application that allows multiple users to watch serial consoles

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-pam --with-libwrap --with-openssl
USE_RC_SUBR=	conserver

MAN1=	console.1
MAN5=	conserver.cf.5 conserver.passwd.5
MAN8=	conserver.8

OPTIONS_DEFINE=	UDS
UDS_DESC=	Use Unix domain sockets for client/server

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MUDS}
CONFIGURE_ARGS+=	--with-uds
.endif

.include <bsd.port.post.mk>

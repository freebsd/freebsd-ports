# New ports collection makefile for:	conserver.com
# Date created:		9 December 2001
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

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

OPTIONS=	UDS	"Use Unix domain sockets for client/server"	off

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

.include <bsd.port.pre.mk>

.if defined(WITH_UDS)
CONFIGURE_ARGS+=	--with-uds
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	conserver.com
# Date created:		9 December 2001
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conserver
PORTVERSION=	8.1.14
CATEGORIES=	comms
MASTER_SITES=	http://www.conserver.com/ \
		ftp://ftp.conserver.com/conserver/
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Application that allows multiple users to watch serial consoles

GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-pam --with-libwrap --with-openssl
USE_RC_SUBR=	conserver.sh

MAN1=	console.1
MAN5=	conserver.cf.5 conserver.passwd.5
MAN8=	conserver.8

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

.include <bsd.port.mk>

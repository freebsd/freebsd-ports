# New ports collection makefile for:	conserver.com
# Date created:		9 December 2001
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conserver
PORTVERSION=	7.2.7
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.conserver.com/conserver/
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Application that allows multiple users to watch serial consoles

GNU_CONFIGURE=	YES
USE_REINPLACE=	yes
CONFIGURE_ARGS=	--with-master=${DEFAULTHOST} --with-port=${DEFAULTPORT} \
		--with-libwrap

MAN1=	console.1
MAN5=	conserver.cf.5 conserver.passwd.5
MAN8=	conserver.8

DEFAULTPORT?=	782
DEFAULTHOST?=	localhost

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
CONFIGURE_ARGS+=--with-64bit
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's@/usr/local/bin@${PREFIX}/sbin@' \
		${WRKSRC}/conserver/conserver.rc.in

.include <bsd.port.post.mk>

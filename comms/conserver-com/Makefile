# New ports collection makefile for:	conserver.com
# Date created:		9 December 2001
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	conserver
PORTVERSION=	7.2.4
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.conserver.com/conserver/
PKGNAMESUFFIX=	-com

MAINTAINER=	kuriyama@FreeBSD.org

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

.if ${ARCH} == "alpha" || ${ARCH} == "sparc64" || ${ARCH} == "ia64"
CONFIGURE_ARGS+=--with-64bit
.endif

post-patch:
	${REINPLACE_CMD} \
		-e 's@/usr/local/bin@${PREFIX}/sbin@' \
		${WRKSRC}/conserver/conserver.rc

post-install:
	${LN} -sf ../conserver.rc ${PREFIX}/etc/rc.d/conserver.sh-

.include <bsd.port.post.mk>

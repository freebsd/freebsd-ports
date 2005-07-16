# New ports collection makefile for:	dnsmasq
# Date created:				1 June 2003
# Whom:					Steven Honson <steven@honson.org>
#
# $FreeBSD$
#

PORTNAME=	dnsmasq
PORTVERSION=	2.22
CATEGORIES=	dns
MASTER_SITES=	http://www.thekelleys.org.uk/dnsmasq/

MAINTAINER=	steven@honson.org
COMMENT=	Lightweight, easy to configure DNS forwarder and DHCP server

MAN8=		dnsmasq.8
PLIST_FILES=	sbin/dnsmasq etc/dnsmasq.conf.example

USE_GETOPT_LONG=yes
MAKE_ENV=	LIBS="${LDFLAGS}" RPM_OPT_FLAGS="${CPPFLAGS}"

.if defined(WITHOUT_IPV6)
MAKE_ENV+=	-DNO_IPV6
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500037
USE_RC_SUBR=	dnsmasq.sh
.else
USE_RCORDER=	dnsmasq.sh
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${PREFIX}/etc
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>

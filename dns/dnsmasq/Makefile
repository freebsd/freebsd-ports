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

USE_REINPLACE=	yes
USE_RC_SUBR=	yes

MAN8=		dnsmasq.8
PLIST_FILES=	sbin/dnsmasq etc/dnsmasq.conf.example etc/rc.d/dnsmasq.sh

USE_GETOPT_LONG=	yes
MAKE_ENV+=	"LIBS=${LDFLAGS}"
.if defined(WITHOUT_IPV6)
MAKE_ENV+=	RPM_OPT_FLAGS="${CPPFLAGS} -DNO_IPV6"
.else
MAKE_ENV+=	RPM_OPT_FLAGS="${CPPFLAGS}"
.endif

post-build:
	@${SED} -e "s|%%RC_SUBR%%|${RC_SUBR}|g;s|%%PREFIX%%|${PREFIX}|g" \
	<${FILESDIR}/dnsmasq.sh >${WRKDIR}/dnsmasq.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/dnsmasq ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/dnsmasq.conf.example ${PREFIX}/etc
	${INSTALL_SCRIPT} ${WRKDIR}/dnsmasq.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${PREFIX}/man/man8

.include <bsd.port.mk>

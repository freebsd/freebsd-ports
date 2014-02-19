# Created by: Clement Laforet <clement@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dnsproxy
PORTVERSION=	1.16
CATEGORIES=	dns
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	proxy for DNS queries

BUILD_DEPENDS=	${LOCALBASE}/lib/libevent.so:${PORTSDIR}/devel/libevent

GNU_CONFIGURE=	yes

USE_RC_SUBR=	dnsproxy

PLIST_FILES=	sbin/dnsproxy etc/${PORTNAME}/dnsproxy.conf.sample \
		man/man1/dnsproxy.1.gz

SUB_FILES=	pkg-message
PLIST_DIRS=	%%ETCDIR%%

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnsproxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dnsproxy.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsproxy.conf ${STAGEDIR}${ETCDIR}/dnsproxy.conf.sample

.include <bsd.port.mk>

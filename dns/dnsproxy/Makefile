PORTNAME=	dnsproxy
PORTVERSION=	1.17
PORTREVISION=	5
CATEGORIES=	dns
MASTER_SITES=	http://www.wolfermann.org/

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Proxy for DNS queries
WWW=		https://www.wolfermann.org/dnsproxy.html

LICENSE=	MIT

LIB_DEPENDS=	libevent.so:devel/libevent

GNU_CONFIGURE=	yes

USES=		groff
USE_RC_SUBR=	dnsproxy

PLIST_FILES=	etc/${PORTNAME}/dnsproxy.conf.sample \
		share/man/man1/dnsproxy.1.gz \
		sbin/dnsproxy

SUB_FILES=	pkg-message

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dnsproxy ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/dnsproxy.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/dnsproxy.conf ${STAGEDIR}${ETCDIR}/dnsproxy.conf.sample

.include <bsd.port.mk>

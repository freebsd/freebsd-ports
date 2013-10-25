# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	dnscrypt-proxy
PORTVERSION=	1.3.3
CATEGORIES=	dns
MASTER_SITES=	http://download.dnscrypt.org/dnscrypt-proxy/ \
		http://www.dns-lab.com/downloads/dnscrypt-proxy/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Boost privacy and security of DNS

LIB_DEPENDS=	libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libsodium.so:${PORTSDIR}/security/libsodium

GNU_CONFIGURE=	yes
USES=		gmake

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		README-PLUGINS.markdown README-WINDOWS.markdown \
		README.markdown TECHNOTES THANKS

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/hostip.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>

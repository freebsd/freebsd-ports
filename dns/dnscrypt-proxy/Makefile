# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	dnscrypt-proxy
PORTVERSION=	1.3.1
CATEGORIES=	dns
MASTER_SITES=	http://download.dnscrypt.org/dnscrypt-proxy/ \
		http://www.dns-lab.com/downloads/dnscrypt-proxy/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Boost privacy and security of DNS

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo \
		sodium:${PORTSDIR}/security/libsodium

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

MAN8=		dnscrypt-proxy.8 hostip.8

PORTDOCS=	AUTHORS COPYING ChangeLog INSTALL NEWS README \
		README-PLUGINS.markdown README-WINDOWS.markdown \
		README.markdown TECHNOTES THANKS

.include <bsd.port.options.mk>

pre-install:
	@${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/man/hostip.8 ${MAN8PREFIX}/man/man8/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>

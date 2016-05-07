# Created by: Leo Vandewoestijne <freebsd@dns-lab.com>
# $FreeBSD$

PORTNAME=	dnscrypt-proxy
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	dns
MASTER_SITES=	http://download.dnscrypt.org/dnscrypt-proxy/ \
		http://www.dns-lab.com/downloads/dnscrypt-proxy/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Boost privacy and security of DNS

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libsodium.so:security/libsodium

GNU_CONFIGURE=	yes
USES=		execinfo gmake

OPTIONS_DEFINE=	DOCS
OPTIONS_SINGLE=	RCWHICH
OPTIONS_SINGLE_RCWHICH=	RCSINGLE RCMULTI
RCWHICH_DESC=	rc script to use:
RCSINGLE_DESC=	use default rc script for single daemon
RCMULTI_DESC=	use experimental rc script for multiple instances
OPTIONS_DEFAULT=RCSINGLE

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MRCMULTI}
USE_RC_SUBR=	${PORTNAME}_multi
SUB_FILES=	pkg-message_multi
.else
USE_RC_SUBR=	${PORTNAME}
SUB_FILES=	pkg-message
.endif

USERS=		_dnscrypt-proxy

PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README* THANKS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/man/hostip.8 ${STAGEDIR}${MAN8PREFIX}/man/man8

.include <bsd.port.mk>

# New ports collection makefile for:	dnscrypt-proxy
# Date created:		15 May 2012
# Whom:			Leo Vandewoestijne <freebsd@dns-lab.com>
#
# $FreeBSD$
#

PORTNAME=	dnscrypt-proxy
PORTVERSION=	0.9.3
CATEGORIES=	dns
MASTER_SITES=	http://cloud.github.com/downloads/opendns/dnscrypt-proxy/ \
		http://www.dns-lab.com/downloads/dnscrypt-proxy/

MAINTAINER=	freebsd@dns-lab.com
COMMENT=	Boost privacy and security of DNS

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

SUB_FILES=	pkg-message

USE_RC_SUBR=	${PORTNAME}

MAN8=		dnscrypt-proxy.8 dnscrypt-proxy.8.markdown

PORTDOCS=	AUTHORS ChangeLog COPYING INSTALL NEWS \
		README README.markdown TECHNOTES THANKS

pre-install:
	@${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8 ${MAN8PREFIX}/man/man8/
	@${INSTALL_MAN} ${WRKSRC}/man/dnscrypt-proxy.8.markdown ${MAN8PREFIX}/man/man8/

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}/
.endif
	@${CAT} ${WRKDIR}/pkg-message

.include <bsd.port.mk>

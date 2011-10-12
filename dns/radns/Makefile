# New ports collection makefile for:   radns
# Date created:        11 July 2011
# Whom:                Michael Cardell Widerkrantz <mc@hack.org>
#
# $FreeBSD$
#

PORTNAME=	radns
PORTVERSION=	20110809
CATEGORIES=	dns
MASTER_SITES=	http://hack.org/mc/hacks/radns/

MAINTAINER=	mc@hack.org
COMMENT=	IPv6 DNS server address autoconfiguration client

LICENSE=	ISCL

USE_BZIP2=	yes
USE_RC_SUBR=	radns

USERS=		radns
GROUPS=		radns

USE_RC_SUBR=	radns
SUB_FILES=	pkg-message

MAN8=		radns.8

PORTDOCS=	LICENSE README README.FreeBSD NEWS

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 900000
BROKEN=		does not compile on FreeBSD 9.X
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/LICENSE ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/README.FreeBSD ${DOCSDIR}
	@${INSTALL_MAN} ${WRKSRC}/NEWS ${DOCSDIR}

.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

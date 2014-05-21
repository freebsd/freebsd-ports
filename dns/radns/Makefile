# Created by: Michael Cardell Widerkrantz <mc@hack.org>
# $FreeBSD$

PORTNAME=	radns
PORTVERSION=	20110809.2
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/}
CATEGORIES=	dns
MASTER_SITES=	http://hack.org/mc/hacks/radns/

MAINTAINER=	mc@hack.org
COMMENT=	IPv6 DNS server address autoconfiguration client

LICENSE=	ISCL

USES=		tar:bzip2
USE_RC_SUBR=	radns

USERS=		radns
GROUPS=		radns

SUB_FILES=	pkg-message

PORTDOCS=	LICENSE README README.FreeBSD NEWS

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

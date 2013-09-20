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

USE_BZIP2=	yes
USE_RC_SUBR=	radns

USERS=		radns
GROUPS=		radns

USE_RC_SUBR=	radns
SUB_FILES=	pkg-message

MAN8=		radns.8

PORTDOCS=	LICENSE README README.FreeBSD NEWS

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "Installing additional documentation to ${DOCSDIR}"
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor

.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

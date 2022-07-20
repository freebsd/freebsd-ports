PORTNAME=	radns
DISTVERSION=	20110809-2
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

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>

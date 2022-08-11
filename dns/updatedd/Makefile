PORTNAME=	updatedd
PORTVERSION=	2.6
PORTREVISION=	2
CATEGORIES=	dns
MASTER_SITES=	SAVANNAH
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	geniusj@ods.org
COMMENT=	Dynamic DNS Update Client supporting multiple services

OPTIONS_DEFINE=	DOCS

USES=		gmake libtool perl5 shebangfix
SHEBANG_FILES=	Documentation/updatedd-pppd-rc
GNU_CONFIGURE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

.include <bsd.port.mk>

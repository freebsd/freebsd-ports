PORTNAME=	drool
DISTVERSION=	2.0.0
CATEGORIES=	dns
MASTER_SITES=	https://www.dns-oarc.net/files/drool/

MAINTAINER=	jaap@NLnetLabs.nl
COMMENT=	Replay DNS traffic from packet capture files

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	dnsjit:dns/dnsjit
BUILD_DEPENDS=	${MY_DEPENDS}
RUN_DEPENDS=	${MY_DEPENDS}

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DATADIR

.include <bsd.port.mk>

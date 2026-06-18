PORTNAME=	gsm
DISTVERSION=	1.0.24
CATEGORIES=	audio
MASTER_SITES=	https://www.quut.com/gsm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Audio converter and library for converting u-law to gsm encoding
WWW=		https://www.quut.com/gsm/

LICENSE=	TU-BERLIN
LICENSE_NAME=	Technische Universitaet Berlin copyright
LICENSE_FILE=	${WRKSRC}/COPYRIGHT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_LDCONFIG=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:R}-pl${DISTVERSION:E}

.include <bsd.port.mk>

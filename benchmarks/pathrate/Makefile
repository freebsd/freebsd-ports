PORTNAME=	pathrate
PORTVERSION=	2.4.1
CATEGORIES=	benchmarks
MASTER_SITES=	http://www.cc.gatech.edu/~dovrolis/bw-est/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Measurement tool for capacity estimation of network paths

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USES=		gmake

WRKSRC=		${WRKDIR}/${PORTNAME}_${PORTVERSION}
MAKEFILE=	makefile

PLIST_FILES=	bin/pathrate_rcv bin/pathrate_snd

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} pathrate_rcv pathrate_snd \
		${STAGEDIR}${PREFIX}/bin)

.include <bsd.port.mk>

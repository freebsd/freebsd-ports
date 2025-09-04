PORTNAME=	hebcal
DISTVERSIONPREFIX=	v
DISTVERSION=	5.9.2.20250725
PORTREVISION=	2
CATEGORIES=	deskutils

MAINTAINER=	rtd24@columbia.edu
COMMENT=	Perpetual Jewish calendar
WWW=		https://hebcal.github.io

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:modules
USE_GITHUB=	yes
GH_TAGNAME=	16a4dbad70c5fd10

PLIST_FILES=	bin/hebcal \
		share/man/man1/hebcal.1.gz

pre-build:
	@${ECHO_CMD} 'package main' > ${WRKSRC}/dcity.go
	@${ECHO_CMD} 'var defaultCity = "New York"' >> ${WRKSRC}/dcity.go

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/hebcal ${STAGEDIR}${PREFIX}/bin/hebcal
	${INSTALL_MAN} ${WRKSRC}/hebcal.1.in ${STAGEDIR}${PREFIX}/share/man/man1/hebcal.1

.include <bsd.port.mk>

# Created by: elbarto@ArcadeBSD.org
# $FreeBSD$

PORTNAME=	dfu-programmer
PORTVERSION=	0.7.2
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Device Firmware Update based USB programmer for Atmel chips

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
LIBS+=		-lusb

PLIST_FILES=	bin/dfu-programmer man/man1/dfu-programmer.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

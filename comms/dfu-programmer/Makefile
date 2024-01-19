PORTNAME=	dfu-programmer
PORTVERSION=	0.7.2
PORTREVISION=	1
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Device Firmware Update based USB programmer for Atmel chips
WWW=		https://dfu-programmer.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
LIBS+=		-lusb

PLIST_FILES=	bin/dfu-programmer share/man/man1/dfu-programmer.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

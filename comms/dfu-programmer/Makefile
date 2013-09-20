# Created by: elbarto@ArcadeBSD.org
# $FreeBSD$

PORTNAME=	dfu-programmer
PORTVERSION=	0.5.5
CATEGORIES=	comms
MASTER_SITES=	SF

MAINTAINER=	byu17@uclive.ac.nz
COMMENT=	Device Firmware Update based USB programmer for Atmel chips

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -lusb

PLIST_FILES=	bin/dfu-programmer

MAN1=		dfu-programmer.1
PORTDOCS=	*

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

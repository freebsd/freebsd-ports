# $FreeBSD$

PORTNAME=	ge-x2212
PORTVERSION=	0.0.2010.09.15
CATEGORIES=	comms hamradio
MASTER_SITES=	http://members.shaw.ca/swstuff/ \
		LOCAL/makc
DISTNAME=	${PORTNAME}-2-15sept2010

MAINTAINER=	shurd@sasktel.net
COMMENT=	EEPROM programmer for GE Phoenix SX Radios

USES=		pkgconfig
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-2

PLIST_FILES=	bin/ge-x2212-2
PORTDOCS=	schematic.txt

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/schematic.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

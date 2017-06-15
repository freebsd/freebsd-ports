# $FreeBSD$

PORTNAME=	ge-x2212
PORTVERSION=	0.0.2010.09.15
PORTREVISION=	1
CATEGORIES=	comms hamradio
MASTER_SITES=	http://members.shaw.ca/swstuff/ \
		LOCAL/makc
DISTNAME=	${PORTNAME}-2-15sept2010

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	EEPROM programmer for GE Phoenix SX Radios

USES=		pkgconfig
USE_GNOME=	libgnomeui
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-2

PLIST_FILES=	bin/ge-x2212-2
PORTDOCS=	schematic.txt

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${FILESDIR}/schematic.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

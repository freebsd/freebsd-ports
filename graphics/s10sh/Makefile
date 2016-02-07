# Created by: John Reynolds <johnjen@reynoldsnet.org>
# $FreeBSD$

PORTNAME=	s10sh
PORTVERSION=	0.2.2
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://www.reynoldsnet.org/s10sh/ \
		http://www.edwinh.org/s10sh/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	USB/serial userspace driver for the Canon PowerShot digital cameras

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		ncurses readline

# Don't extract the libusb bundled with s10sh:
EXTRACT_AFTER_ARGS=	--exclude '*/libusb*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

PORTDOCS=	README
PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

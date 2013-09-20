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

NO_STAGE=	yes
# Don't extract the libusb bundled with s10sh:
EXTRACT_AFTER_ARGS=	--exclude '*/libusb*'

MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README

OPTIONS_DEFINE=	USB

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin/

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

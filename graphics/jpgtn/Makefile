# New ports collection makefile for:	jpgtn
# Date created:		07 September 2001
# Whom:			mb@imp.ch
#
# $FreeBSD$
#

PORTNAME=	jpgtn
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR= apps/graphics/misc

MAINTAINER=	mbr@FreeBSD.org
COMMENT=	Creates thumbnails of JPEG images

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg

MAN1=		jpgtn.1
PLIST_FILES=	bin/jpgtn
USE_REINPLACE=	yes

pre-everything::
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can control program functionality by defining the following variables:"
	@${ECHO_MSG} "===>"
.if !defined(WITH_MAXSIZE)
	@${ECHO_MSG} "===> Define WITH_MAXSIZE to set the maximum allowable thumbnail size"
.endif
.if !defined(WITH_MINSIZE)
	@${ECHO_MSG} "===> Define WITH_MINSIZE to set the minimum allowable thumbnail size"
.endif
	@${ECHO_MSG} "===>"

post-patch:
.if defined(WITH_MAXSIZE)
	@${ECHO_MSG} "Setting MAXSIZE to ${WITH_MAXSIZE}"
	@${REINPLACE_CMD} "s/define MAXSIZE[[:blank:]]*256/define MAXSIZE ${WITH_MAXSIZE}/" ${WRKSRC}/jpgtn.h
	@${REINPLACE_CMD} "s/allowable range (24-256)/allowable range (24-${WITH_MAXSIZE})/" ${WRKSRC}/jpgtn.1
.endif
.if defined(WITH_MINSIZE)
	@${ECHO_MSG} "Setting MINSIZE to ${WITH_MINSIZE}"
	@${REINPLACE_CMD} "s/define MINSIZE[[:blank:]]*24/define MINSIZE ${WITH_MINSIZE}/" ${WRKSRC}/jpgtn.h
	@${REINPLACE_CMD} "s/allowable range (24-)/allowable range (${WITH_MINSIZE}-/" ${WRKSRC}/jpgtn.1
.endif

.include <bsd.port.mk>

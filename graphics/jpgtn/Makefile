# New ports collection makefile for:	jpgtn
# Date created:		07 September 2001
# Whom:			mb@imp.ch
#
# $FreeBSD$
#

PORTNAME=	jpgtn
PORTVERSION=	2.06
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	apps/graphics/misc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Creates thumbnails of JPEG images

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE}

MAN1=		jpgtn.1
PLIST_FILES=	bin/jpgtn

WITH_MAXSIZE?=	2048
WITH_MINSIZE?=	1
WITH_DEFSIZE?=	128

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
.if !defined(WITH_DEFSIZE)
	@${ECHO_MSG} "===> Define WITH_DEFSIZE to set the default thumbnail size"
.endif
	@${ECHO_MSG} "===>"

post-patch:
.if defined(WITH_MAXSIZE)
	@${ECHO_MSG} "Setting MAXSIZE to ${WITH_MAXSIZE}"
	@${REINPLACE_CMD} "s/define MAXSIZE[[:blank:]]*2048/define MAXSIZE ${WITH_MAXSIZE}/" ${WRKSRC}/src/jpgtn.h
.endif
.if defined(WITH_MINSIZE)
	@${ECHO_MSG} "Setting MINSIZE to ${WITH_MINSIZE}"
	@${REINPLACE_CMD} "s/define MINSIZE[[:blank:]]*1/define MINSIZE ${WITH_MINSIZE}/" ${WRKSRC}/src/jpgtn.h
.endif
.if defined(WITH_DEFSIZE)
	@${ECHO_MSG} "Setting DEFAULTSIZE to ${WITH_DEFSIZE}"
	@${REINPLACE_CMD} "s/define DEFAULTSIZE[[:blank:]]*128/define DEFAULTSIZE ${WITH_DEFSIZE}/" ${WRKSRC}/src/jpgtn.h
.endif
	@${REINPLACE_CMD} "s/(2-2048) the size defaults to 128/(${WITH_MINSIZE}-${WITH_MAXSIZE}) the size defaults to ${WITH_DEFSIZE}/" \
		${WRKSRC}/doc/jpgtn.1

.include <bsd.port.mk>

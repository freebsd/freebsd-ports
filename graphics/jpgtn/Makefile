PORTNAME=	jpgtn
PORTVERSION=	2.06
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	SF SUNSITE/apps/graphics/misc

MAINTAINER=	fuz@FreeBSD.org
COMMENT=	Creates thumbnails of JPEG images
WWW=		https://jpgtn.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	obsolete historical tool, use imagemagick instead
EXPIRATION_DATE=	2025-12-31

USES=		jpeg
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-libjpeg=${LOCALBASE}

PLIST_FILES=	bin/jpgtn \
		share/man/man1/jpgtn.1.gz

WITH_MAXSIZE?=	2048
WITH_MINSIZE?=	1
WITH_DEFSIZE?=	128

post-patch:
	@${ECHO_MSG} "Setting MAXSIZE to ${WITH_MAXSIZE}"
	@${REINPLACE_CMD} "s/define MAXSIZE[[:blank:]]*2048/define MAXSIZE ${WITH_MAXSIZE}/" ${WRKSRC}/src/jpgtn.h
	@${ECHO_MSG} "Setting MINSIZE to ${WITH_MINSIZE}"
	@${REINPLACE_CMD} "s/define MINSIZE[[:blank:]]*1/define MINSIZE ${WITH_MINSIZE}/" ${WRKSRC}/src/jpgtn.h
	@${ECHO_MSG} "Setting DEFAULTSIZE to ${WITH_DEFSIZE}"
	@${REINPLACE_CMD} "s/define DEFAULTSIZE[[:blank:]]*128/define DEFAULTSIZE ${WITH_DEFSIZE}/" ${WRKSRC}/src/jpgtn.h
	@${REINPLACE_CMD} "s/(2-2048) the size defaults to 128/(${WITH_MINSIZE}-${WITH_MAXSIZE}) the size defaults to ${WITH_DEFSIZE}/" \
		${WRKSRC}/doc/jpgtn.1

.include <bsd.port.mk>

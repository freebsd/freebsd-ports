# New ports collection makefile for:	wavpack
# Date created:			Fri Jun 24 20:30:04 CEST 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wavpack
PORTVERSION=	4.41.0
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	multimedia@FreeBSD.org
COMMENT=	Compress (and restore) both 16 and 24-bit audio files in .wav format

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget pkgconfig
USE_ICONV=	yes
USE_DOS2UNIX=	cli/*.[ch] include/*.h src/*.[ch]
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

FILES=		include/wavpack.h src/unpack3.c src/words.c cli/md5.c

post-patch:
.for i in ${FILES}
	@cd ${WRKSRC} && ${CP} ${i} ${i}.orig && \
		col < ${i}.orig > ${i}
.endfor

.include <bsd.port.mk>

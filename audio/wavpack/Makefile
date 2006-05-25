# New ports collection makefile for:	wavpack
# Date created:			Fri Jun 24 20:30:04 CEST 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wavpack
PORTVERSION=	4.32
CATEGORIES=	audio
MASTER_SITES=	http://www.wavpack.com/

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Compress (and restore) both 16 and 24-bit audio files in .wav format

GNU_CONFIGURE=	yes
USE_ICONV=	yes
USE_BZIP2=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GNOME=	gnomehack gnometarget
INSTALLS_SHLIB=	yes
FILES=	wavpack.h unpack3.c words.c md5.c

post-patch:
.for i in ${FILES}
	@cd ${WRKSRC} && ${CP} ${i} ${i}.orig && \
		col < ${i}.orig > ${i}
.endfor

.include <bsd.port.mk>

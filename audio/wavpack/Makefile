# New ports collection makefile for:	wavpack
# Date created:			Fri Jun 24 20:30:04 CEST 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wavpack
PORTVERSION=	4.2
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Compress (and restore) both 16 and 24-bit audio files in .wav format

USE_LIBTOOL_VER=15
USE_ICONV=	yes
USE_BZIP2=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
FILES=	wavpack.h unpack3.c words.c md5.c

post-patch:
	@${REINPLACE_CMD} -e 's|libdir)/pkgconfig|prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
.for i in ${FILES}
	@cd ${WRKSRC} && cp ${i} ${i}.orig && \
		col < ${i}.orig > ${i}
.endfor	

.include <bsd.port.mk>

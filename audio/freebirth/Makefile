# New ports collection makefile for:	freebirth
# Date created:				27 Dec 2001
# Whom:					David Yeske <dyeske@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	freebirth
PORTVERSION=	0.3.2
CATEGORIES=	audio
MASTER_SITES=	http://www.bitmechanic.com/projects/freebirth/

MAINTAINER=	dyeske@yahoo.com

USE_GMAKE=	yes
USE_GTK=	yes
USE_X_PREFIX=	yes

pre-build:
	@${PERL} -pi -e 's@-g  -O6@${CFLAGS}@g; s@CC=gcc@CC=${CC}@g; \
			s@^all: freebirth@all: Makefile.deps freebirth @g; \
			s@gtk-config@${GTK_CONFIG}@g; \
			s@^LDFLAGS=@LDFLAGS=\$${LOADLIBES}@g' \
		${WRKSRC}/Makefile
	@${PERL} -pi -e 's@^#define FB_SAMPLES "."@#define FB_SAMPLES "${PREFIX}/share/freebirth"@g;' \
		${WRKSRC}/raw_wave.h

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/freebirth ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/fusebirth ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/freebirth/raw
	${INSTALL_DATA} ${WRKSRC}/raw/*.raw ${PREFIX}/share/freebirth/raw
	${STRIP_CMD} ${PREFIX}/bin/freebirth
	${STRIP_CMD} ${PREFIX}/bin/fusebirth

.include <bsd.port.mk>

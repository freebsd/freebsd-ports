# New ports collection makefile for:	gnomermind
# Date created:				11 April 2001
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gnomermind
PORTVERSION=	1.0
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sobomax@FreeBSD.org

USE_BZIP2=	yes
USE_X_PREFIX=	yes
USE_GNOMENG=	yes
USE_GNOME=	gnomeprefix gnomehack gnomelibs gdkpixbuf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"
MAKE_ENV=	OLD_PO_FILE_INPUT=1

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|DATADIRNAME=lib|DATADIRNAME=share|g' ${WRKSRC}/configure

.include <bsd.port.mk>

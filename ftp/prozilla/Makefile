# New ports collection makefile for:	ftp/prozilla
# Date created:				Jan 24 2003
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	prozilla
PORTVERSION=	2.0.1
CATEGORIES=	ftp
MASTER_SITES=	http://prozilla.genesys.ro/downloads/prozilla/tarballs/

MAINTAINER=	alejandro@varnet.biz
COMMENT=	ProZilla is a fast download accelerator

USE_BZIP2=	yes
USE_GETOPT_LONG=yes
USE_GMAKE=	yes
USE_LIBTOOL_VER=15
USE_REINPLACE=	yes

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		proz.1

post-patch:
	${REINPLACE_CMD} -e 's|CPPFLAGS =|CPPFLAGS = @CPPFLAGS@|' \
		${WRKSRC}/libprozilla/src/Makefile.in

.include <bsd.port.mk>

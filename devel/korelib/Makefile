# New ports collection makefile for:	korelib
# Date created:				10 May 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	korelib
PORTVERSION=	1.0
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rygannon.com/pub/Korelib/

MAINTAINER=	ports@FreeBSD.org

BROKEN=		"Missing dependency on autoheader"

USE_KDELIBS_VER=3
USE_AUTOMAKE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes
USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""

pre-configure:
	${REINPLACE_CMD} -e "s@-g -O2@${CXXFLAGS}@g" -e "s@-O2@${CFLAGS}@g" \
		${WRKSRC}/configure ${WRKSRC}/*/Makefile.in ${WRKSRC}/*/*/Makefile.in

post-install:
	${RM} -f ${PREFIX}/lib/libkore.la

.include <bsd.port.mk>

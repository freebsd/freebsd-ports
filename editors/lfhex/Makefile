# ex:ts=8
# New ports collection makefile for:	lfhex
# Date created:			Jul 6, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	lfhex
PORTVERSION=	0.3.2
PORTREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved

MAINTAINER=	ports@freebsd.org
COMMENT=	"Large file hex editor"

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
USE_QT_VER=	3
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-qt-moc=${MOC}
USE_GMAKE=	yes
CONFIGURE_ENV=	CXXFLAGS="${PTHREAD_CFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s,%%LOCALBASE%%,${LOCALBASE},g ; \
		s,%%X11BASE%%,${X11BASE},g" ${WRKSRC}/src/Makefile.in

post-configure:
	${REINPLACE_CMD} -e "s,LFLAGS =,LFLAGS = ${PTHREAD_LIBS} ${LDFLAGS}," ${WRKSRC}/src/Makefile

.include <bsd.port.mk>

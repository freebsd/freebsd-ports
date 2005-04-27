# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	2.6
PORTREVISION=	4
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Rich Site Summary viewer

USE_KDEBASE_VER=	3
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBQT="-lqt-mt ${PTHREAD_LIBS}" KDB2HTML=${TRUE}
MAKE_ENV=	LIBQT="-lqt-mt ${PTHREAD_LIBS}" KDB2HTML=${TRUE}
USE_REINPLACE=	yes

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

post-patch:
	${REINPLACE_CMD} -e 's|$$(LIB_KFILE)|-lkio|' ${WRKSRC}/krss/Makefile.in
	${REINPLACE_CMD} -e 's|-pedantic||;s|-Wmissing-prototypes||' \
		${WRKSRC}/configure

.include <bsd.port.mk>

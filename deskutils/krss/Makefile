# ex:ts=8
# Ports collection makefile for:	K.R.S.S.
# Date created:			Apr 17, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	krss
PORTVERSION=	3.0
PORTREVISION=	1
CATEGORIES=	deskutils kde
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Rich Site Summary viewer

DEPRECATED=	Depends on QT3; unmaintained
EXPIRATION_DATE=	2013-07-01

USE_KDEBASE_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
MAKE_JOBS_SAFE=	yes

QTCPPFLAGS+=	${PTHREAD_CFLAGS}
QTCFGLIBS+=	${PTHREAD_LIBS}

INSTALLS_ICONS=	yes

post-patch:
	${REINPLACE_CMD} -e 's|$$(LIB_KFILE)|-lkio|' ${WRKSRC}/krss/Makefile.in
	${REINPLACE_CMD} -e 's|-pedantic||;s|-Wmissing-prototypes||' \
		${WRKSRC}/configure

.include <bsd.port.mk>

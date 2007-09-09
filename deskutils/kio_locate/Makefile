# New ports collection makefile for:	kio_locate
# Date created:		2007-08-26
# Whom:			fusselbaer <e-ports@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	kio_locate
PORTVERSION=	0.4.4
CATEGORIES=	deskutils kde
MASTER_SITES=	http://arminstraub.com/downloads/kio-locate/
DISTNAME=	kio-locate_${PORTVERSION}

MAINTAINER=	e-ports@gmx.de
COMMENT=	Locate KIO for Konqueror

WRKSRC=	    ${WRKDIR}/kio-locate-${PORTVERSION}

USE_SCONS=	yes
USE_KDELIBS_VER=	3

.if !defined(WITHOUT_NLS)
    USE_GETTEXT=	yes
    PLIST_SUB+=		NLS=""
.else
    PLIST_SUB+=		NLS="@comment "
.endif

post-extract:
	${REINPLACE_CMD} 's/LocateProtocol:://' ${WRKSRC}/src/kio_locate.h
pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${LOCALBASE}/bin/scons -C ${WRKSRC} prefix=${PREFIX}

.include <bsd.port.mk>

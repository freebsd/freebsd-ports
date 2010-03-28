# New ports collection makefile for:	waheela
# Date created:				2009-08-10
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$

PORTNAME=	waheela
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	audio kde
MASTER_SITES=	http://linux.wuertz.org/dists/sid/main/source/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Fullscreen mode for Amarok 2.x

RUN_DEPENDS=	amarok>=2:${PORTSDIR}/audio/amarok-kde4

USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdehier kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

ADD_NEWLINE_TO=	background.h \
		dateTime.cpp \
		dateTime.h \
		metadata.cpp \
		metadata.h \
		playProgress.cpp \
		playProgress.h

post-patch:
.for i in ${ADD_NEWLINE_TO}
	${ECHO_CMD} >> ${WRKSRC}/src/widgets/${i}
.endfor

.include <bsd.port.mk>

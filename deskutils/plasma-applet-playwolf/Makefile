# New ports collection makefile for:	plasma-applet-playwolf
# Date Created:				2009-02-22
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	playwolf
PORTVERSION=	0.8.1
PORTREVISION=	2
CATEGORIES=	deskutils kde
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Amarok 2.x plasma applet for KDE4

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_KDE4=	automoc4 kdeprefix kdelibs
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network opengl phonon svg webkit xml xmlpatterns \
		qmake_build moc_build rcc_build uic_build
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	lib/kde4/plasma_applet_playwolf.so \
		share/kde4/services/plasma-applet-playwolf.desktop

WRKSRC=		${WRKDIR}/${PORTNAME}

ADD_NEWLINE_TO=	flowlayout.cpp \
		flowlayout.h \
		lyricswidget.cpp \
		playwolf.cpp \
		playwolf.h \
		wolfbuttons.cpp \
		wolflabel.h

post-patch:
.for i in ${ADD_NEWLINE_TO}
	${ECHO_CMD} >> ${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>

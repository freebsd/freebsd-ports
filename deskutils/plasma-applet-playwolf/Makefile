# $FreeBSD$

PORTNAME=	playwolf
PORTVERSION=	0.8.1
PORTREVISION=	6
CATEGORIES=	deskutils kde
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	plasma-applet-

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Amarok 2.x plasma applet for KDE4

LICENSE=	GPLv2

USES=		cmake tar:bzip2
USE_KDE4=	automoc4 kdelibs
USE_QT4=	gui dbus network opengl phonon svg webkit xml xmlpatterns \
		qmake_build moc_build rcc_build uic_build

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

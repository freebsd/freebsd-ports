# $FreeBSD$

PORTNAME=	waheela
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	audio kde
MASTER_SITES=	http://linux.wuertz.org/dists/sid/main/source/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Fullscreen mode for Amarok 2.x

RUN_DEPENDS=	amarok>=2:${PORTSDIR}/audio/amarok-kde4

USES=		cmake
NO_STAGE=	yes
USE_KDE4=	automoc4 kdeprefix kdehier kdelibs
USE_QT4=	gui dbus network svg xml \
		qmake_build moc_build rcc_build uic_build

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

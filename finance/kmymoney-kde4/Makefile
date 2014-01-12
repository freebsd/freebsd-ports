# $FreeBSD$

PORTNAME=	kmymoney
PORTVERSION=	4.6.4
PORTREVISION=	1
CATEGORIES=	finance kde
MASTER_SITES=	SF/${PORTNAME}2/KMyMoney-KDE4/${PORTVERSION}

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 personal finance manager

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_graph.so:${PORTSDIR}/devel/boost-libs \
		libalkimia.so:${PORTSDIR}/finance/libalkimia

USE_XZ=		yes
USES=		cmake pkgconfig
USE_QT4=	gui dbus network phonon sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix automoc4 kdelibs pimlibs sharedmime
USE_LDCONFIG=	yes

NO_STAGE=	yes

MAN1=		kmymoney.1

OPTIONS_DEFINE=		NLS CALENDAR KBANKING OFX QUOTES
OPTIONS_DEFAULT=	CALENDAR
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

NLS_USES=		gettext
NLS_CMAKE_ON=		-DENABLE_NLS:BOOL=ON
NLS_CMAKE_OFF=		-DENABLE_NLS:BOOL=OFF

CALENDAR_DESC=		Enable Calendar plugin
CALENDAR_LIB_DEPENDS=	libical.so:${PORTSDIR}/devel/libical
CALENDAR_CMAKE_ON=	-DENABLE_LIBICAL:BOOL=ON
CALENDAR_CMAKE_OFF=	-DENABLE_LIBICAL:BOOL=OFF

KBANKING_DESC=		Enable KBanking plugin
KBANKING_LIB_DEPENDS=	libgwengui-qt4.so:${PORTSDIR}/devel/gwenhywfar-qt4 \
			libaqbanking.so:${PORTSDIR}/finance/aqbanking
KBANKING_CMAKE_ON=	-DENABLE_KBANKING:BOOL=ON
KBANKING_CMAKE_OFF=	-DENABLE_KBANKING:BOOL=OFF

OFX_DESC=		Enable OFX plugin
OFX_LIB_DEPENDS=	libofx.so:${PORTSDIR}/finance/libofx
OFX_CMAKE_ON=		-DENABLE_LIBOFX:BOOL=ON
OFX_CMAKE_OFF=		-DENABLE_LIBOFX:BOOL=OFF

QUOTES_DESC=		Enable online price quotes
QUOTES_USES=		perl5
QUOTES_USE=		PERL5=run
QUOTES_RUN_DEPENDS=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
			p5-Finance-Quote>=0:${PORTSDIR}/finance/p5-Finance-Quote \
			p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
			p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
			p5-libwww>=0:${PORTSDIR}/www/p5-libwww

.include <bsd.port.mk>

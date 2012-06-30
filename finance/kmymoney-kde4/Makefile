# New ports collection makefile for:	KMyMoney
# Date created:				21 June 2004
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	kmymoney
PORTVERSION=	4.6.2
PORTREVISION=	2
CATEGORIES=	finance kde
MASTER_SITES=	SF/${PORTNAME}2/KMyMoney-KDE4/${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	KDE 4.x-based personal finance manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	boost_graph.4:${PORTSDIR}/devel/boost-libs \
		alkimia.4:${PORTSDIR}/finance/libalkimia

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT4=	gui dbus network phonon sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix automoc4 kdelibs pimlibs sharedmime
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kmymoney.1

OPTIONS=	CALENDAR "Enable Calendar plugin" on \
		KBANKING "Enable KBanking plugin" off \
		OFX "Enable OFX plugin" off \
		QUOTES "Enable online price quotes" off

.include <bsd.port.options.mk>

.if defined(WITH_CALENDAR)
LIB_DEPENDS+=	ical.44:${PORTSDIR}/devel/libical
CMAKE_ARGS+=	-DENABLE_LIBICAL:BOOL=ON
PLIST_SUB+=	WITH_CALENDAR=""
.else
CMAKE_ARGS+=	-DENABLE_LIBICAL:BOOL=OFF
PLIST_SUB+=	WITH_CALENDAR="@comment "
.endif

.if defined(WITH_KBANKING)
LIB_DEPENDS+=	gwengui-qt4.0:${PORTSDIR}/devel/gwenhywfar \
		aqbanking.33:${PORTSDIR}/finance/aqbanking
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=ON
PLIST_SUB+=	WITH_KBANKING=""
.else
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=OFF
PLIST_SUB+=	WITH_KBANKING="@comment "
.endif

.if defined(WITH_OFX)
LIB_DEPENDS+=	ofx.5:${PORTSDIR}/finance/libofx
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=ON
PLIST_SUB+=	WITH_OFX=""
.else
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=OFF
PLIST_SUB+=	WITH_OFX="@comment "
.endif

.if defined(WITH_QUOTES)
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	p5-Date-Manip>=0:${PORTSDIR}/devel/p5-Date-Manip \
		p5-Finance-Quote>=0:${PORTSDIR}/finance/p5-Finance-Quote \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-XML-Writer>=0:${PORTSDIR}/textproc/p5-XML-Writer \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww
.endif

.if !defined(PACKAGE_BUILDING) && defined(WITH_KBANKING) && !exists(${LOCALBASE}/lib/libgwengui-qt4.so)
IGNORE=		please rebuild devel/gwenhywfar with the WITH_QT4 option set
.endif

.include <bsd.port.mk>

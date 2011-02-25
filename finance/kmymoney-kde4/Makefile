# New ports collection makefile for:	KMyMoney
# Date created:				21 June 2004
# Whom:					Alexander Novitsky
#
# $FreeBSD$
#

PORTNAME=	kmymoney
PORTVERSION=	4.5.2
PORTREVISION=	1
CATEGORIES=	finance
MASTER_SITES=	SF/${PORTNAME}2/KMyMoney-KDE4/${PORTVERSION}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	KDE 4.x-based personal finance manager

BUILD_DEPENDS=	${LOCALBASE}/share/xml/docbook/4.2/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml
LIB_DEPENDS=	boost_graph.4:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_CMAKE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui dbus network phonon sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_KDE4=	kdehier kdeprefix automoc4 kdelibs pimlibs sharedmime
USE_LDCONFIG=	yes
USE_GETTEXT=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kmymoney.1

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

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
LIB_DEPENDS+=	aqbanking.31:${PORTSDIR}/finance/aqbanking
QT_COMPONENTS+=	qt3support
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=ON
PLIST_SUB+=	WITH_KBANKING=""
.else
CMAKE_ARGS+=	-DENABLE_KBANKING:BOOL=OFF
PLIST_SUB+=	WITH_KBANKING="@comment "
.endif

.if defined(WITH_OFX)
LIB_DEPENDS+=	ofx.4:${PORTSDIR}/finance/libofx
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=ON
PLIST_SUB+=	WITH_OFX=""
.else
CMAKE_ARGS+=	-DENABLE_LIBOFX:BOOL=OFF
PLIST_SUB+=	WITH_OFX="@comment "
.endif

.if defined(WITH_QUOTES)
USE_PERL5_RUN=	yes
RUN_DEPENDS+=	${SITE_PERL}/Date/Manip.pm:${PORTSDIR}/devel/p5-Date-Manip \
		${SITE_PERL}/Finance/Quote.pm:${PORTSDIR}/finance/p5-Finance-Quote \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
.endif

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	kmymoney
PORTVERSION=	4.8.0
PORTREVISION=	5
CATEGORIES=	finance kde
MASTER_SITES=	KDE/stable/${PORTNAME}/${PORTVERSION}/src

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	KDE4 personal finance manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libboost_graph.so:devel/boost-libs \
		libalkimia.so:finance/libalkimia \
		libgmp.so:math/gmp \
		libgpgme.so:security/gpgme \
		libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error

USES=		cmake kde:4 pkgconfig shared-mime-info shebangfix tar:xz
USE_QT4=	corelib gui dbus declarative network phonon script sql svg xml \
		qmake_build moc_build rcc_build uic_build
USE_KDE=	automoc4 kdelibs pimlibs soprano
USE_LDCONFIG=	yes

SHEBANG_FILES=	kmymoney/misc/financequote.pl

OPTIONS_DEFINE=		NLS CALENDAR KBANKING OFX QUOTES
OPTIONS_DEFAULT=	CALENDAR
OPTIONS_SUB=		yes
NO_OPTIONS_SORT=	yes

NLS_USES=		gettext
NLS_CMAKE_ON=		-DBUILD_po:BOOL=ON
NLS_CMAKE_OFF=		-DBUILD_po:BOOL=OFF

CALENDAR_DESC=		Enable Calendar plugin
CALENDAR_LIB_DEPENDS=	libical.so:devel/libical
CALENDAR_CMAKE_ON=	-DENABLE_LIBICAL:BOOL=ON
CALENDAR_CMAKE_OFF=	-DENABLE_LIBICAL:BOOL=OFF

KBANKING_DESC=		Enable KBanking plugin
KBANKING_LIB_DEPENDS=	libgwenhywfar.so:devel/gwenhywfar \
			libgwengui-qt4.so:devel/gwenhywfar-qt4 \
			libaqbanking.so:finance/aqbanking
KBANKING_CMAKE_ON=	-DENABLE_KBANKING:BOOL=ON
KBANKING_CMAKE_OFF=	-DENABLE_KBANKING:BOOL=OFF

OFX_DESC=		Enable OFX plugin
OFX_LIB_DEPENDS=	libofx.so:finance/libofx
OFX_CMAKE_ON=		-DENABLE_LIBOFX:BOOL=ON
OFX_CMAKE_OFF=		-DENABLE_LIBOFX:BOOL=OFF

QUOTES_DESC=		Enable online price quotes
QUOTES_USES=		perl5
QUOTES_USE=		PERL5=run
QUOTES_RUN_DEPENDS=	p5-Date-Manip>=0:devel/p5-Date-Manip \
			p5-Finance-Quote>=0:finance/p5-Finance-Quote \
			p5-XML-Parser>=0:textproc/p5-XML-Parser \
			p5-XML-Writer>=0:textproc/p5-XML-Writer \
			p5-libwww>=0:www/p5-libwww

.include <bsd.port.mk>

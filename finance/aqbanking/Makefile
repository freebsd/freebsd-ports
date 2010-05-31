# New ports collection makefile for:	aqbanking
# Date created:		June 2005
# Whom:                 Sam Lawrance <lawrance@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	aqbanking
PORTVERSION=	4.2.4
PORTREVISION=	3
CATEGORIES=	finance
MASTER_SITES=	http://www2.aquamaniac.de/sites/download/
DISTFILES=	download.php\?package=03\&release=50\&file=01\&dummy=${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Online banking interface and financial data framework

LIB_DEPENDS=	gwenhywfar.58:${PORTSDIR}/devel/gwenhywfar \
		gmp.10:${PORTSDIR}/math/gmp

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
MAKE_JOBS_UNSAFE=	yes

CFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}" \
		LDFLAGS="${LDFLAGS}"

USE_LDCONFIG=	${PREFIX}/lib/aqbanking/plugins/29/bankinfo \
		${PREFIX}/lib/aqbanking/plugins/29/imexporters \
		${PREFIX}/lib/aqbanking/plugins/29/providers \
		${PREFIX}/lib

OPTIONS=	KTOBLZCHECK "KtoBlzCheck support" off \
		QT3 "Build QT3 frontend" off \
		QT4 "Build QT4 frontend" on

.include <bsd.port.options.mk>

# no configure option to disable ktoblzcheck support (yet)
.if defined(WITH_KTOBLZCHECK) || exists(${LOCALBASE}/lib/libktoblzcheck.so.4)
LIB_DEPENDS+=	ktoblzcheck.6:${PORTSDIR}/finance/ktoblzcheck
.endif

.if !defined(WITH_QT3) && !defined(WITH_QT4)
CONFIGURE_ARGS+=--with-frontends=""
.elif defined(WITH_QT3) && !defined(WITH_QT4)
CONFIGURE_ARGS+=--with-frontends="qbanking"
.elif !defined(WITH_QT3) && defined(WITH_QT4)
CONFIGURE_ARGS+=--with-frontends="q4banking"
.endif

.if defined(WITH_QT3)
USE_QT_VER=	3
QT_NONSTANDARD=	yes
CONFIGURE_ENV+=	LIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		QTDIR="${QT_PREFIX}"
USE_LDCONFIG+=	${PREFIX}/lib/aqbanking/plugins/29/frontends/qbanking/cfgmodules
PLIST_SUB+=	WITH_QT3=""
.else
PLIST_SUB+=     WITH_QT3="@comment "
.endif

.if defined(WITH_QT4)
#USE_QT_VER=    4
#QT_COMPONENTS= gui qt3support moc_build uic_build
QT_NONSTANDARD=	yes
.include "${PORTSDIR}/Mk/bsd.qt.mk"
BUILD_DEPENDS+=	moc-qt4:${PORTSDIR}/devel/qt4-moc \
		uic-qt4:${PORTSDIR}/devel/qt4-uic
LIB_DEPENDS+=	QtGui.4:${PORTSDIR}/x11-toolkits/qt4-gui \
		Qt3Support.4:${PORTSDIR}/devel/qt4-qt3support
CONFIGURE_ENV+= LIBS="${QTCFGLIBS} ${PTHREAD_LIBS}" \
		QTDIR="${QT_PREFIX}"
USE_LDCONFIG+=	${PREFIX}/lib/aqbanking/plugins/29/frontends/q4banking/cfgmodules
PLIST_SUB+=	WITH_QT4=""
.else
PLIST_SUB+=     WITH_QT4="@comment "
.endif

post-install:
# install dummy files for directories shared between QT3 & QT4 frontends
.for dir in 	lib/aqbanking/plugins/29/debugger \
		lib/aqbanking/plugins/29/debugger/aqhbci \
		lib/aqbanking/plugins/29/frontends \
		lib/aqbanking/plugins/29/wizards \
		share/aqbanking/frontends
			${MKDIR} ${PREFIX}/${dir}
			${TOUCH} ${PREFIX}/${dir}/.keep_me
.endfor
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

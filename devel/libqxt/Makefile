# Created by: gahr
# $FreeBSD$

PORTNAME=	libqxt
PORTVERSION=	0.6.2
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://dev.libqxt.org/libqxt/get/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extension library for Qt

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

BUILD_DEPENDS=	bash:shells/bash

USE_BDB=	44+
USES=		tar:bzip2
USE_QT4=	qmake_build moc_build rcc_build corelib gui gui \
		designer
USE_LDCONFIG=	${PREFIX}/lib/qxt

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-libdir ${PREFIX}/lib/qxt \
		-qmake-bin ${QMAKE} \
		-featuredir ${PREFIX}/${QT_MKSPECDIR_REL}/features \
		-I ${BDB_INCLUDE_DIR} \
		-I ${LOCALBASE}/include/avahi-compat-libdns_sd \
		-L ${BDB_LIB_DIR} \
		-verbose
DESTDIRNAME=	INSTALL_ROOT

COMMIT=		dadc327c2a6a
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${COMMIT}

PLIST_SUB+=	SHVER_1=${PORTVERSION} \
		SHVER_2=${PORTVERSION:R} \
		SHVER_3=${PORTVERSION:R:R}

OPTIONS_DEFAULT=	AVAHI
OPTIONS_SINGLE=		ZEROCONF
OPTIONS_SINGLE_ZEROCONF=	AVAHI MDNSRESPONDER
AVAHI_LIB_DEPENDS=	libdns_sd.so:net/avahi-libdns
MDNSRESPONDER_LIB_DEPENDS=	libdns_sd.so:net/mDNSResponder

STRIP_FILES=	lib/qxt/lib*.so.${PORTVERSION} \
		${QT_PLUGINDIR_REL}/designer/libQxtDesignerPlugins.so

post-patch:
	${REINPLACE_CMD} -e '\
	    s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	    /^QXT_MODULES/s|docs||g' \
	    ${WRKSRC}/configure
	${REINPLACE_CMD} -e \
	    's,$$$$\[QT_INSTALL_PLUGINS\],${PREFIX}/${QT_PLUGINDIR_REL},' \
	    ${WRKSRC}/src/designer/designer.pro
	${REINPLACE_CMD} -e '\
	    s|ldb|l${BDB_LIB_NAME} -L${BDB_LIB_DIR}|g; \
	    /INCLUDEPATH/s|\.|${BDB_INCLUDE_DIR}|g' \
	    ${WRKSRC}/config.tests/db/db.pro

regression-test:
	cd ${WRKSRC}/tests && \
	    ${QMAKE} tests.pro && ${MAKE} && \
	    ${FIND} unit -type f -perm -0755 -exec {} \;

post-install:
	${STRIP_CMD} ${STRIP_FILES:S,^,${STAGEDIR}${PREFIX}/,}

.include <bsd.port.mk>

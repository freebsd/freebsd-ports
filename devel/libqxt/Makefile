# Created by: gahr
# $FreeBSD$

PORTNAME=	libqxt
PORTVERSION=	0.6.2
CATEGORIES=	devel
MASTER_SITES=	http://dev.libqxt.org/libqxt/get/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Extension library for Qt

LIB_DEPENDS=	dns_sd:${PORTSDIR}/net/avahi-libdns
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_BDB=	44+
USE_BZIP2=	yes
USE_QT4=	qmake_build moc_build rcc_build corelib gui gui \
		designer
USE_LDCONFIG=	${PREFIX}/lib/qxt

QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	-prefix ${PREFIX} \
		-libdir ${PREFIX}/lib/qxt \
		-qmake-bin ${QMAKE} \
		-featuredir ${PREFIX}/share/qt4/mkspecs/features \
		-I ${BDB_INCLUDE_DIR} \
		-I ${LOCALBASE}/include/avahi-compat-libdns_sd \
		-L ${BDB_LIB_DIR} \
		-verbose

COMMIT=		dadc327c2a6a
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${COMMIT}

PLIST_SUB+=	SHVER_1=${PORTVERSION} \
    		SHVER_2=${PORTVERSION:R} \
		SHVER_3=${PORTVERSION:R:R}

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -e '\
	    s|%%PREFIX%%|${PREFIX}|g; \
	    s|/bin/bash|${LOCALBASE}/bin/bash|g; \
	    /^QXT_MODULES/s|docs||g' \
	    ${WRKSRC}/configure \
	    ${WRKSRC}/src/designer/designer.pro
	${REINPLACE_CMD} -e '\
	    s|ldb|l${BDB_LIB_NAME} -L${BDB_LIB_DIR}|g; \
	    /INCLUDEPATH/s|\.|${BDB_INCLUDE_DIR}|g' \
	    ${WRKSRC}/config.tests/db/db.pro

regression-test:
	cd ${WRKSRC}/tests && \
	    ${QMAKE} tests.pro && ${MAKE} && \
	    ${FIND} unit -type f -perm -0755 -exec {} \;

.include <bsd.port.mk>

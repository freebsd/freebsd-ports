# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevt
DISTVERSION=	alpha-20181216
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libevt/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tooling to access the Windows Event Log (EVT) format

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	python${PYTHON2_DEFAULT}:lang/python${PYTHON2_DEFAULT:S/.//} \
		python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//}
RUN_DEPENDS=	python${PYTHON2_DEFAULT}:lang/python${PYTHON2_DEFAULT:S/.//} \
		python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//}
LIB_DEPENDS=	libfwnt.so:devel/libfwnt \
		libregf.so:devel/libregf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python2 --enable-python3 \
		--with-libfwnt=${LOCALBASE} --with-libregf=${LOCALBASE}
CONFIGURE_ENV=	PYTHON2_CONFIG=${LOCALBASE}/bin/python${PYTHON2_DEFAULT}-config \
		PYTHON3=${LOCALBASE}/bin/python${PYTHON3_DEFAULT} \
		PYTHON3_CONFIG=${LOCALBASE}/bin/python${PYTHON3_DEFAULT}-config
USES=		libtool pathfix
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}
PLIST_SUB=	PYTHON2_SITELIBDIR=lib/python${PYTHON2_DEFAULT}/site-packages \
		PYTHON3_SITELIBDIR=lib/python${PYTHON3_DEFAULT}/site-packages

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>

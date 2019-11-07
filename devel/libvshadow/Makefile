# Created by: MANTANI Nobutaka <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libvshadow
PORTVERSION=	20191103
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libvshadow/releases/download/${PORTVERSION}/ \
		LOCAL/antoine
DISTNAME=	${PORTNAME}-alpha-${PORTVERSION}

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library to support the Volume Service Snapshot (VSS) format

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	python${PYTHON2_DEFAULT}:lang/python${PYTHON2_DEFAULT:S/.//} \
		python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//}
RUN_DEPENDS=	python${PYTHON2_DEFAULT}:lang/python${PYTHON2_DEFAULT:S/.//} \
		python${PYTHON3_DEFAULT}:lang/python${PYTHON3_DEFAULT:S/.//}

USES=		fuse libtool pathfix pkgconfig
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python2 --enable-python3
CONFIGURE_ENV=	PYTHON2_CONFIG=${LOCALBASE}/bin/python${PYTHON2_DEFAULT}-config \
		PYTHON3=${LOCALBASE}/bin/python${PYTHON3_DEFAULT} \
		PYTHON3_CONFIG=${LOCALBASE}/bin/python${PYTHON3_DEFAULT}-config
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
PLIST_SUB=	PYTHON2_SITELIBDIR=lib/python${PYTHON2_DEFAULT}/site-packages \
		PYTHON3_SITELIBDIR=lib/python${PYTHON3_DEFAULT}/site-packages

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.mk>

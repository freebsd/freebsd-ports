# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libregf
DISTVERSION=	alpha-20170130
CATEGORIES=	devel
MASTER_SITES=	https://github.com/libyal/libregf/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tools to support the Windows NT Registry File format

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfwnt.so:devel/libfwnt \
		libfwsi.so:devel/libfwsi

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libfwnt=${LOCALBASE} --with-libfwsi=${LOCALBASE}
USES=		fuse libtool pathfix pkgconfig python
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

OPTIONS_DEFINE=	DOCS NLS

NLS_USES=	gettext
NLS_CONFIGURE_ON=	--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

PORTDOCS=	AUTHORS ChangeLog

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevt
DISTVERSION=	alpha-20141026
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSYm01VnUtLXNUZ2M/ \
		https://github.com/libyal/libevt/releases/download/${PORTVERSION:E}/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tooling to access the Windows Event Log (EVT) format

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python --with-libintl-prefix=${LOCALBASE} ${ICONV_CONFIGURE_ARG}
USES=		gettext iconv libtool pathfix python:2
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

PORTDOCS=	AUTHORS ChangeLog

OPTIONS_DEFINE=	DOCS

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

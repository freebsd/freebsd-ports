PORTNAME=	xchm
PORTVERSION=	1.36
PORTREVISION=	1
CATEGORIES=	deskutils

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Windows HTML Help (.chm) viewer for UNIX
WWW=		https://github.com/rzvncj/xCHM

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libchm.so:misc/chmlib

USES=		compiler:c++11-lang desktop-file-utils localbase autoreconf
USE_GITHUB=	yes
GH_ACCOUNT=	rzvncj
GH_PROJECT=	xCHM
USE_WX=		3.0+
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
LDFLAGS+=	-lpthread

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>

PORTNAME=	madedit
PORTVERSION=	0.2.9
PORTREVISION=	26
CATEGORIES=	editors
MASTER_SITES=	SF/${PORTNAME}/MadEdit/MadEdit-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open-source and cross-platform text/hex editor
WWW=		http://madedit.sourceforge.net/

DEPRECATED=	Abandoned project and use deprecated wxgtk28
EXPIRATION_DATE=	2022-12-31

LICENSE=	GPLv2

LIB_DEPENDS=	libboost_regex.so:devel/boost-libs

USES=		gettext pkgconfig dos2unix desktop-file-utils xorg
USE_WX=		2.8
USE_XORG=	x11

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-wx-config=${WX_CONFIG}
LIBS+=		-L${LOCALBASE}/lib -lX11

.include <bsd.port.mk>

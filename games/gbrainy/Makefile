# $FreeBSD$

PORTNAME=	gbrainy
PORTVERSION=	2.2.2
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	games
MASTER_SITES=	http://gent.softcatala.org/jmas/gbrainy/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Brain teaser game and trainer

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	mautil:devel/mono-addins \
		${LOCALBASE}/bin/bash:shells/bash
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		gettext gmake gnome mono pathfix pkgconfig shebangfix
USE_GNOME=	gtksharp20 gnomesharp20 intltool
SHEBANG_FILES=	src/Clients/Classical/gbrainy.in
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
MAKE_ENV+=	MONO_REGISTRY_PATH=${WRKDIR}

INSTALLS_ICONS=	yes

.include <bsd.port.mk>

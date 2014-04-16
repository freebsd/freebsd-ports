# Created by: Pav Lucistnik <pav@FreeBSD.org>
# $FreeBSD$

PORTNAME=	scribes
PORTVERSION=	0.4.b954
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	https://launchpadlibrarian.net/66129407/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-dev-${PORTVERSION:E:S/b/build/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Slick yet powerful text editor for GNOME

LICENSE=	GPLv2

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dbus>0:${PORTSDIR}/devel/py-dbus \
		${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg \
		${LOCALBASE}/share/xml/docbook/4.5:${PORTSDIR}/textproc/docbook-xml \
		yelp:${PORTSDIR}/x11/yelp

USES=		gettext gmake shebangfix tar:bzip2
SHEBANG_FILES=	scribes.in
USE_GNOME=	gnomeprefix pygnomeextras pygtksourceview gnomedocutils
USE_PYTHON=	yes
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
INSTALLS_OMF=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

NO_STAGE=	yes
post-install:
	@${PYTHON_CMD} -m compileall ${PREFIX}/lib/scribes

.include <bsd.port.mk>

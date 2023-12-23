PORTNAME=	go-for-it
DISTVERSION=	1.9.6
PORTREVISION=	2
CATEGORIES=	deskutils

PATCH_SITES=	https://github.com/JMoerman/Go-For-It/commit/
PATCHFILES=	6b0f86bd403ece8c2f7813e442258881e11925df.diff:-p1

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Stylish to-do list with built-in productivity timer
WWW=		https://github.com/JMoerman/Go-For-It

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcanberra.so:audio/libcanberra \
		libnotify.so:devel/libnotify

USES=		cmake compiler:c11 gettext gnome pkgconfig vala:build
CMAKE_ARGS=	-DAPP_SYSTEM_NAME:STRING=${PORTNAME}
USE_GITHUB=	yes
GH_ACCOUNT=	JMoerman
GH_PROJECT=	Go-For-It
USE_GNOME=	cairo glib20 gtk30 intltool
GLIB_SCHEMAS=	com.github.jmoerman.go-for-it.gschema.xml

GNU_CONFIGURE=	yes

.include <bsd.port.mk>

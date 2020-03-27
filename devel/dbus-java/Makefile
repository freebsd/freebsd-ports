# $FreeBSD$

PORTNAME=	dbus-java
PORTVERSION=	2.7
CATEGORIES=	devel java
MASTER_SITES=	https://dbus.freedesktop.org/releases/dbus-java/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Java API for D-BUS

LICENSE=	ACADEMIC LGPL21+
LICENSE_COMB=	dual
LICENSE_NAME_ACADEMIC=	Academic Free License version 2.1
LICENSE_FILE_ACADEMIC=	${WRKSRC}/COPYING
LICENSE_FILE_LGPL21+ =	${WRKSRC}/COPYING
LICENSE_PERMS_ACADEMIC=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libunix-java.so:devel/libmatthew

USES=		gettext gmake
USE_JAVA=	yes
JAVA_VERSION=	7+

MAKE_ARGS=	MANPREFIX=${MAN1PREFIX}/share/man/man1
.if defined(WITH_DEBUG)
MAKE_ARGS+=	DEBUG=enable
.endif
MAKE_ENV=	DOCPREFIX=${DOCSDIR} \
		JARPREFIX=${JAVAJARDIR} \
		JAVA_HOME=${JAVA_HOME} \
		JAVAUNIXJARDIR=${JAVAJARDIR} \
		JAVAUNIXLIBDIR=${LOCALBASE}/lib

ALL_TARGET=	bin
INSTALL_TARGET=	install-bin

NO_ARCH=	yes

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES
OPTIONS_SUB=		yes

MANPAGES_BUILD_DEPENDS=		docbook-to-man>0:textproc/docbook-to-man
MANPAGES_ALL_TARGET=		man
MANPAGES_INSTALL_TARGET=	install-man

.include <bsd.port.mk>

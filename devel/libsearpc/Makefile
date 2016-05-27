# $FreeBSD$

PORTNAME=	libsearpc
PORTVERSION=	3.0.7
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Simple RPC framework based on GObject System in C

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libgobject-2.0.so:devel/glib20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.0-latest

USES=		autoreconf libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEALIB=		${SEAFILE_SERVER}/seafile/lib

USERS=		seafile
GROUPS=		${USERS}

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR}

post-install:
	@${MKDIR} ${STAGEDIR}${SEALIB}
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}

.include <bsd.port.mk>

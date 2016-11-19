# $FreeBSD$

PORTNAME=	libsearpc
PORTVERSION=	3.1.0
CATEGORIES=	devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Simple RPC framework based on GObject System in C

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

LIB_DEPENDS=	libjansson.so:devel/jansson \
		libgobject-2.0.so:devel/glib20

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.1-latest

USES=		autoreconf gettext libtool pathfix pkgconfig python:2
USE_LDCONFIG=	yes

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
	${RM} -r ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}

.include <bsd.port.mk>

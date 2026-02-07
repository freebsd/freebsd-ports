PORTNAME=	clixon
PORTVERSION=	6.5.0
CATEGORIES=	devel

MAINTAINER=	dave@dogwood.com
COMMENT=	YANG-based toolchain including CLI, NETCONF and RESTCONF interfaces
WWW=		https://www.clicon.org/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

BUILD_DEPENDS=	cligen>=${PORTVERSION}:devel/cligen \
		nghttp2>=0:www/nghttp2
RUN_DEPENDS=	cligen>=${PORTVERSION}:devel/cligen \
		nghttp2>=0:www/nghttp2

USES=		autoreconf bison compiler:c11 gmake

USE_GITHUB=	yes
GH_ACCOUNT=	clicon

USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--sysconfdir=${ETCDIR} \
		--with-cligen=${LOCALBASE}
CONFIGURE_ENV=	YACC="bison -y"
MAKE_ARGS=	wwwdir=${PREFIX}/sbin \
		wwwuser=${WWWOWN}

SUB_FILES=	pkg-message

USERS=		clixon
GROUPS=		clixon

PLIST_SUB=	LIBMAJORVERSION=${PORTVERSION:R:R} \
		LIBVERSION=${PORTVERSION:R}

OPTIONS_DEFAULT=		NATIVE
OPTIONS_SINGLE=			RESTCONF
OPTIONS_SINGLE_RESTCONF=	NATIVE FCGI OFF
OPTIONS_SUB=	yes

FCGI_DESC=	FCGI interface for stand-alone web rev-proxy (eg nginx)
NATIVE_DESC=	Use embedded web server
OFF_DESC=	Disable restconf

FCGI_LIB_DEPENDS=	libfcgi.so:www/fcgi
FCGI_CONFIGURE_ON=	--with-restconf=fcgi
NATIVE_BUILD_DEPENDS=	nghttp2>=0:www/nghttp2
NATIVE_RUN_DEPENDS=	nghttp2>=0:www/nghttp2
NATIVE_CONFIGURE_ON=	--with-restconf=native
OFF_CONFIGURE_ON=	--without-restconf

.include <bsd.port.mk>

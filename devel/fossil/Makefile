# $FreeBSD$

PORTNAME=	fossil
PORTVERSION=	2.6
PORTREVISION=	0
DISTVERSIONPREFIX=	src-
PORTEPOCH=	2
CATEGORIES=	devel www
MASTER_SITES=	http://fossil-scm.org/index.html/uv/

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT-BSD2.txt

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		ssl
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_RC_SUBR=	fossil
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/fossil

OPTIONS_DEFINE=	JSON FUSE STATIC TH1HOOKS TCL
OPTIONS_DEFAULT=JSON
JSON_DESC=	JSON API support
FUSE_DESC=	Enable fossil fusefs command
TH1HOOKS_DESC=	Enable TH1 command and web page hooks
TCL_DESC=	Enable Tcl integration

JSON_CONFIGURE_ON=	--json
STATIC_CONFIGURE_ON=	--static
FUSE_CONFIGURE_OFF=	--disable-fusefs
TH1HOOKS_CONFIGURE_ON=	--with-th1-hooks
TCL_CONFIGURE_ON=	--with-tcl-stubs --with-tcl=${TCL_LIBDIR}
TCL_USES=		tcl
TCL_CFLAGS=		-DTCL_LIBRARY_NAME=\\\"libtcl${TCL_SHLIB_VER}.so\\\" \
			-DTCL_MINOR_OFFSET=7
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs
FUSE_USES=		localbase:ldflags

post-patch-FUSE-on:
	@${REINPLACE_CMD} -e 's/define-append LIBS -lfuse/& -pthread/' ${WRKSRC}/auto.def

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fossil

.include <bsd.port.mk>

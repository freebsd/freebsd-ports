# $FreeBSD$

PORTNAME=	fossil
PORTVERSION=	1.37
DISTVERSIONPREFIX=	src-
PORTEPOCH=	2
CATEGORIES=	devel www
MASTER_SITES=	http://fossil-scm.org/index.html/uv/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DSCM with built-in wiki, http interface and server, tickets database

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT-BSD2.txt

WRKSRC=		${WRKDIR}/Fossil_2017-01-16_205854_1669115ab9

USES=		ssl
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}
USE_RC_SUBR=	fossil
MAKE_JOBS_UNSAFE=yes

PLIST_FILES=	bin/fossil

OPTIONS_DEFINE=	JSON FUSE STATIC
OPTIONS_DEFAULT=	JSON
JSON_DESC=	JSON API support
FUSE_DESC=	Enable fossil fusefs command

JSON_CONFIGURE_ON=	--json
STATIC_CONFIGURE_ON=	--static
FUSE_CONFIGURE_OFF=	--disable-fusefs
FUSE_LIB_DEPENDS=	libfuse.so:sysutils/fusefs-libs
FUSE_USES=		localbase:ldflags

post-patch-FUSE-on:
	@${REINPLACE_CMD} -e 's/define-append LIBS -lfuse/& -pthread/' ${WRKSRC}/auto.def

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/fossil

.include <bsd.port.mk>

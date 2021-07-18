PORTNAME=	pgbackrest
DISTVERSION=	2.33
CATEGORIES=	databases

MAINTAINER=	schoutm@gmail.com
COMMENT=	Reliable PostgreSQL Backup & Restore

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/../LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		gmake gnome pkgconfig pgsql ssl
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

USE_GITHUB=	yes
GH_TAGNAME=	release/${DISTVERSION}

WRKSRC_SUBDIR=	src

ALL_TARGET=

CONFIGURE_ARGS=	--with-configdir="${LOCALBASE}/etc/pgbackrest"

OPTIONS_DEFINE=	ZSTD

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_CONFIGURE_OFF=	ac_cv_lib_zstd_ZSTD_isError=no
ZSTD_CONFIGURE_ON=	ac_cv_lib_zstd_ZSTD_isError=yes

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/pgbackrest
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pgbackrest

.include <bsd.port.mk>

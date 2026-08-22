PORTNAME=	pgbackrest
DISTVERSION=	2.59.1
CATEGORIES=	databases
MASTER_SITES=	https://github.com/pgbackrest/pgbackrest/releases/download/release/${DISTVERSION}/

MAINTAINER=	schoutm@gmail.com
COMMENT=	Reliable PostgreSQL Backup & Restore
WWW=		https://pgbackrest.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4

USES=		gnome meson pgsql pkgconfig python ssl
USE_GNOME=	libxml2

MESON_ARGS=	-Dconfigdir="${ETCDIR}" -Dlibsystemd=disabled

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		SFTP ZSTD

SFTP_DESC=		Enable SFTP storage support

SFTP_LIB_DEPENDS=	libssh2.so:security/libssh2
SFTP_MESON_ENABLED=	libssh2

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ENABLED=	libzstd

post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>

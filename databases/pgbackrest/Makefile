PORTNAME=	pgbackrest
DISTVERSIONPREFIX=	release/
DISTVERSION=	2.51
CATEGORIES=	databases

MAINTAINER=	schoutm@gmail.com
COMMENT=	Reliable PostgreSQL Backup & Restore
WWW=		https://pgbackrest.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	liblz4.so:archivers/liblz4 \
		libyaml.so:textproc/libyaml

USES=		gnome meson pgsql pkgconfig python ssl
USE_GITHUB=	yes
USE_GNOME=	libxml2

MESON_ARGS+=	-Dconfigdir="${LOCALBASE}/etc/pgbackrest"

BINARY_ALIAS=	python3=${PYTHON_CMD}

OPTIONS_DEFINE=		LZ4 SFTP ZSTD
OPTIONS_DEFAULT=	LZ4

SFTP_DESC=	Enable SFTP storage support

LZ4_LIB_DEPENDS=	liblz4.so:archivers/liblz4
LZ4_MESON_ON=		-Dliblz4=enabled
LZ4_MESON_OFF=		-Dliblz4=disabled

SFTP_LIB_DEPENDS=	libssh2.so:security/libssh2
SFTP_MESON_ON=		-Dlibssh2=enabled
SFTP_MESON_OFF=		-Dlibssh2=disabled

ZSTD_LIB_DEPENDS=	libzstd.so:archivers/zstd
ZSTD_MESON_ON=		-Dlibzstd=enabled
ZSTD_MESON_OFF=		-Dlibzstd=disabled

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/pgbackrest

.include <bsd.port.mk>

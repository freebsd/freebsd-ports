# Created by: Mark Foster <mark@foster.cc>
# $FreeBSD$

PORTNAME=	firefly
PORTVERSION=	1696
PORTREVISION=	15
CATEGORIES=	audio
MASTER_SITES=	SF/fireflyserver-server/Sources/mt-daapd/svn-${PORTVERSION}
DISTNAME=	mt-daapd-svn-${PORTVERSION}

MAINTAINER=	info@NetOcean.de
COMMENT=	Open-source media server for the Roku SoundBridge and iTunes

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/include/vorbis/codec.h:audio/libvorbis \
		${LOCALBASE}/include/FLAC/metadata.h:audio/flac
RUN_DEPENDS=	oggdec:audio/vorbis-tools \
		flac:audio/flac
LIB_DEPENDS=	libogg.so:audio/libogg \
		libsqlite3.so:databases/sqlite3 \
		libid3tag.so:audio/libid3tag

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-id3tag=${LOCALBASE} --enable-sqlite3 \
		--enable-oggvorbis --enable-flac --localstatedir=/var
USES=		libtool
INSTALL_TARGET=	install-strip

DAAPD_USER?=	daapd
DAAPD_GROUP?=	daapd
DAAPD_DBDIR?=	/var/db/${PORTNAME}
USE_RC_SUBR=	mt-daapd
USERS=		${DAAPD_USER}
GROUPS=		${DAAPD_GROUP}

SUB_LIST+=	DAAPD_USER=${DAAPD_USER} \
		DAAPD_GROUP=${DAAPD_GROUP} \
		DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_FILES=	pkg-message
PLIST_SUB+=	DAAPD_DBDIR=${DAAPD_DBDIR} \
		DAAPD_USER=${DAAPD_USER} \
		DAAPD_GROUP=${DAAPD_GROUP}

USE_LDCONFIG=	yes

USE_GCC=	any

OPTIONS_DEFINE=	JAPANESE DOCS
JAPANESE_DESC=	Japanese support in ID3 tags

JAPANESE_EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_scan-mp3.c
JAPANESE_USES=		iconv
JAPANESE_CONFIGURE_ON=	--enable-iconv

pre-everything::
	@${ECHO_CMD} "Define vars below if you need:"
	@${ECHO_CMD} "DAAPD_USER=${DAAPD_USER} (default: daapd)"
	@${ECHO_CMD} "DAAPD_GROUP=${DAAPD_GROUP} (default: daapd)"
	@${ECHO_CMD} "DAAPD_DBDIR=${DAAPD_DBDIR} (default: /var/db/${PORTNAME})"

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.conf \
		${STAGEDIR}${PREFIX}/etc/${PORTNAME}/mt-daapd.conf.sample
	@${MKDIR} ${STAGEDIR}${DAAPD_DBDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README AUTHORS COPYING CREDITS \
	ChangeLog INSTALL NEWS TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor


.include <bsd.port.mk>

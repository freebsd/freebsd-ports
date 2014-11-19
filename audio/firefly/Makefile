# Created by: Mark Foster <mark@foster.cc>
# $FreeBSD$

PORTNAME=	firefly
PORTVERSION=	1696
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://nightlies.fireflymediaserver.org/nightlies/svn-${PORTVERSION}/ \
		http://www.magnesium.net/~mdf/distfiles/
DISTNAME=	mt-daapd-svn-${PORTVERSION}

MAINTAINER=	info@netocean.de
COMMENT=	Open-source media server for the Roku SoundBridge and iTunes

LICENSE=	GPLv2
BROKEN=		Does not fetch

BUILD_DEPENDS=	${LOCALBASE}/include/vorbis/codec.h:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/include/FLAC/metadata.h:${PORTSDIR}/audio/flac
RUN_DEPENDS=	oggdec:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac
LIB_DEPENDS=	libogg.so:${PORTSDIR}/audio/libogg \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libid3tag.so:${PORTSDIR}/audio/libid3tag

GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--prefix=${PREFIX} --with-id3tag=${PREFIX} \
			--enable-sqlite3 --enable-oggvorbis --enable-flac
USES=		libtool

DAAPD_USER?=	daapd
DAAPD_GROUP?=	daapd
DAAPD_DBDIR?=	${PREFIX}/var/db/${PORTNAME}
USE_RC_SUBR=	mt-daapd
USERS=		${DAAPD_USER}
GROUPS=		${DAAPD_GROUP}

PLIST_SUB+=	DAAPD_DBDIR=${DAAPD_DBDIR} \
		DAAPD_USER=${DAAPD_USER} \
		DAAPD_GROUP=${DAAPD_GROUP} \
		DATADIR=${DATADIR}

USE_LDCONFIG=	yes

USE_GCC=	any

OPTIONS_DEFINE=	JAPANESE DOCS
JAPANESE_DESC=	Japanese support in ID3 tags

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MJAPANESE}
EXTRA_PATCHES=	${FILESDIR}/extra-patch-src_scan-mp3.c
USES+=		iconv
CONFIGURE_ARGS+=	--enable-iconv
.endif

pre-everything::
	@${ECHO_CMD} "Define vars below if you need:"
	@${ECHO_CMD} "DAAPD_USER=${DAAPD_USER} (default: daapd)"
	@${ECHO_CMD} "DAAPD_GROUP=${DAAPD_GROUP} (default: daapd)"
	@${ECHO_CMD} "DAAPD_DBDIR=${DAAPD_DBDIR} (default: ${PREFIX}/var/db/${PORTNAME})"

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in README AUTHORS COPYING CREDITS \
	ChangeLog INSTALL NEWS TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.conf \
		${STAGEDIR}${PREFIX}/etc/mt-daapd.conf.sample
	@${MKDIR} ${STAGEDIR}${DAAPD_DBDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${CHMOD} 0755 ${STAGEDIR}${DAAPD_DBDIR}
	@${CHMOD} 0755 ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

# New ports collection makefile for: mt-daapd-devel
# Date created:                26 Nov 2007
# Whom:                        Mark Foster <mark@foster.cc>
# $FreeBSD$
#

PORTNAME=	firefly
PORTVERSION=	1696
PORTREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	http://nightlies.fireflymediaserver.org/nightlies/svn-${PORTVERSION}/ \
		http://www.magnesium.net/~mdf/distfiles/
DISTNAME=	mt-daapd-svn-${PORTVERSION}

MAINTAINER=	mark@foster.cc
COMMENT=	Open-source media server for the Roku SoundBridge and iTunes

BUILD_DEPENDS=	${LOCALBASE}/include/vorbis/codec.h:${PORTSDIR}/audio/libvorbis \
		${LOCALBASE}/include/FLAC/metadata.h:${PORTSDIR}/audio/flac
RUN_DEPENDS=	oggdec:${PORTSDIR}/audio/vorbis-tools \
		flac:${PORTSDIR}/audio/flac
LIB_DEPENDS=	ogg:${PORTSDIR}/audio/libogg \
		sqlite3.8:${PORTSDIR}/databases/sqlite3 \
		id3tag.0:${PORTSDIR}/audio/libid3tag

CONFLICTS=	mt-daapd-0.2.*

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--prefix=${LOCALBASE} --with-id3tag=${PREFIX} --enable-sqlite3 --enable-oggvorbis --enable-flac

#USE_AUTOTOOLS=	autoheader:261 autoconf:261:env

DAAPD_USER?=	daapd
DAAPD_GROUP?=	daapd
DAAPD_DBDIR?=	${PREFIX}/var/db/${PORTNAME}
USE_RC_SUBR=	mt-daapd

PLIST_SUB+=	DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_LIST+=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_FILES+=	pkg-install pkg-deinstall

USE_LDCONFIG=	yes

pre-everything::
	@${ECHO_CMD} "Define vars bellow if you need:"
	@${ECHO_CMD} "DAAPD_USER=${DAAPD_USER} (default: daapd)"
	@${ECHO_CMD} "DAAPD_GROUP=${DAAPD_GROUP} (default: daapd)"
	@${ECHO_CMD} "DAAPD_DBDIR=${DAAPD_DBDIR} (default: ${PREFIX}/var/db/${PORTNAME})"

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' \
	    ${WRKSRC}/configure

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in README AUTHORS COPYING CREDITS \
	ChangeLog INSTALL NEWS TODO
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@[ -f ${PREFIX}/etc/mt-daapd.conf.sample ] || \
		${INSTALL_DATA} ${WRKSRC}/contrib/mt-daapd.conf \
		${PREFIX}/etc/mt-daapd.conf.sample
	@${MKDIR} ${DAAPD_DBDIR}
	@${MKDIR} ${DATADIR}
	@${CHMOD} 0755 ${DAAPD_DBDIR}
	@${CHMOD} 0755 ${DATADIR}
	@${CHOWN} ${DAAPD_USER}:${DAAPD_GROUP} ${DAAPD_DBDIR}
	@${CHOWN} ${DAAPD_USER}:${DAAPD_GROUP} ${DATADIR}
	${LN} -sf ${PREFIX}/lib/mt-daapd/plugins/libout-daap.so.0.0 ${PREFIX}/lib/mt-daapd/plugins/libout-daap.so
	${LN} -sf ${PREFIX}/lib/mt-daapd/plugins/librsp.so.0.0 ${PREFIX}/lib/mt-daapd/plugins/librsp.so
	${LN} -sf ${PREFIX}/lib/mt-daapd/plugins/libssc-script.so.0.0 ${PREFIX}/lib/mt-daapd/plugins/libssc-script.so

	@${ECHO_MSG} "This port installs a sample configuration file in"
	@${ECHO_MSG} "${LOCALBASE}/etc/mt-daapd.conf.sample"
	@${ECHO_MSG} "You probably should move/copy this file to mt-daapd.conf"
	@${ECHO_MSG} "and customize to fit your needs."

.include <bsd.port.mk>

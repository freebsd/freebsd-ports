# New ports collection makefile for:	mt-daapd
# Date created:				10 March 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	mt-daapd
PORTVERSION=	0.2.4.2
PORTREVISION=	1
CATEGORIES=	audio japanese
MASTER_SITES=	SF

MAINTAINER=	mark@foster.cc
COMMENT=	Multithread daapd yet another Server for Apple iTunes

#BUILD_DEPENDS=	${LOCALBASE}/lib/libgdbm.a:${PORTSDIR}/databases/gdbm
LIB_DEPENDS=	gdbm.3:${PORTSDIR}/databases/gdbm
LIB_DEPENDS+=	id3tag.0:${PORTSDIR}/audio/libid3tag

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CFLAGS="${CFLAGS} ${PTHREAD_CFLAGS}" \
		CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		LIBS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=		--with-id3tag=${PREFIX} --with-gdbm-includes=${LOCALBASE}/include

USE_AUTOTOOLS=	autoheader:261 autoconf:261:env

USE_ICONV=	yes
PATCH_SITES+=	http://www.apionet.or.jp/~tomi/
PATCH_SITES+=	${MASTER_SITE_LOCAL}
PATCHFILES+=	mt-daapd-0.2.4.1-cp932.patch
PATCH_DIST_STRIP+=	-p1

DAAPD_USER?=	daapd
DAAPD_GROUP?=	daapd
DAAPD_DBDIR?=	/var/db/${PORTNAME}
USE_RC_SUBR=	mt-daapd.sh

PLIST_SUB+=	DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_LIST+=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_FILES+=	pkg-install pkg-deinstall mt-daapd.conf

pre-everything::
	@${ECHO_CMD} "Define vars below if you need:"
	@${ECHO_CMD} "DAAPD_USER=${DAAPD_USER} (default: daapd)"
	@${ECHO_CMD} "DAAPD_GROUP=${DAAPD_GROUP} (default: daapd)"
	@${ECHO_CMD} "DAAPD_DBDIR=${DAAPD_DBDIR} (default: /var/db/${PORTNAME})"

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
	@[ -f ${PREFIX}/etc/mt-daapd.conf ] || \
		${INSTALL_DATA} ${WRKDIR}/mt-daapd.conf \
			${PREFIX}/etc/mt-daapd.conf
	@${INSTALL_DATA} ${WRKDIR}/mt-daapd.conf ${PREFIX}/etc/mt-daapd.conf.sample
	@${MKDIR} ${DAAPD_DBDIR}
	@${MKDIR} ${DATADIR}
	@${CHMOD} 0755 ${DAAPD_DBDIR}
	@${CHMOD} 0755 ${DATADIR}
	@${CHOWN} ${DAAPD_USER}:${DAAPD_GROUP} ${DAAPD_DBDIR}
	@${CHOWN} ${DAAPD_USER}:${DAAPD_GROUP} ${DATADIR}

.include <bsd.port.mk>

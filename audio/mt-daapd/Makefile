# New ports collection makefile for:	mt-daapd
# Date created:				10 March 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	mt-daapd
PORTVERSION=	0.2.4.2
PORTREVISION=	2
CATEGORIES=	audio japanese
MASTER_SITES=	SF

MAINTAINER=	mark@foster.cc
COMMENT=	Multithread daapd yet another Server for Apple iTunes

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Use audio/firefly instead

LIB_DEPENDS+=	gdbm.3:${PORTSDIR}/databases/gdbm \
		id3tag.0:${PORTSDIR}/audio/libid3tag

CONFLICTS=	firefly-[0-9]*

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-id3tag=${LOCALBASE} \
		--with-gdbm-includes=${LOCALBASE}/include

USE_ICONV=	yes
PATCH_SITES+=	http://shishimaru.the-ninja.jp/\
		${MASTER_SITE_LOCAL}
PATCHFILES+=	mt-daapd-0.2.4.1-cp932.patch
PATCH_DIST_STRIP+=	-p1

DAAPD_USER?=	daapd
DAAPD_GROUP?=	daapd
DAAPD_DBDIR?=	${DAAPD_MASTERDIR}/var/db/${PORTNAME}
USERS=		${DAAPD_USER}
GROUPS=		${DAAPD_GROUP}
USE_RC_SUBR=	mt-daapd

PLIST_SUB+=	DAAPD_DBDIR=${DAAPD_DBDIR}
SUB_LIST+=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP}\
		DAAPD_DBDIR=${DAAPD_DBDIR}\
		DAAPD_MASTERDIR=${DAAPD_MASTERDIR}
SUB_FILES+=	mt-daapd.conf

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_CMD} "Define vars below if you need:"
	@${ECHO_CMD} "DAAPD_USER=${DAAPD_USER} (default: daapd)"
	@${ECHO_CMD} "DAAPD_GROUP=${DAAPD_GROUP} (default: daapd)"
	@${ECHO_CMD} "DAAPD_DBDIR=${DAAPD_DBDIR} (default: ${DAAPD_MASTERDIR}/var/db/${PORTNAME})"

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
	@${ECHO_MSG}
	@${ECHO_MSG} "This port installs a sample configuration file in"
	@${ECHO_MSG} "${PREFIX}/etc/mt-daapd.conf.sample"
	@${ECHO_MSG} "You probably should move/copy this file to mt-daapd.conf"
	@${ECHO_MSG} "and customize to fit your needs."
	@${ECHO_MSG}

.include <bsd.port.post.mk>

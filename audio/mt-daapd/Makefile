# New ports collection makefile for:	mt-daapd
# Date created:				10 March 2004
# Whom:					Meno Abels <meno.abels@adviser.com>
#
# $FreeBSD$
#

PORTNAME=	mt-daapd
PORTVERSION=	0.1.1
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mt-daapd

MAINTAINER=	Meno.Abels@Adviser.com
COMMENT=	Multithread daapd yet another Server for Apple iTunes

LIB_DEPENDS=	id3tag.2:${PORTSDIR}/audio/libid3tag

MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}" \
		LDFLAGS="${LDFLAGS}" LIBS="${LIBS}" \
		INSTALL_PROGRAM="${INSTALL_PROGRAM}"

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	AUTOCONF=autoconf259 AUTOHEADER=autoheader259 CC="${CC} -pthread"
CONFIGURE_ARGS=	--with-id3tag=${PREFIX}

USE_AUTOHEADER_VER=	259
WANT_AUTOCONF_VER=	259

DAAPD_USER=	daapd
DAAPD_GROUP=	daapd

FILES_SUB=	USER=${DAAPD_USER} GROUP=${DAAPD_GROUP} \
		PREFIX=${PREFIX} LOGDIR=${LOGDIR} DOCSDIR=${DOCSDIR} \
		LOCALBASE=${LOCALBASE}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in README AUTHORS COPYING CREDITS \
	ChangeLog INSTALL NEWS TODO
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/mt-daapd.sh > ${WRKDIR}/mt-daapd.sh
	${INSTALL_SCRIPT} ${WRKDIR}/mt-daapd.sh ${PREFIX}/etc/rc.d/mt-daapd.sh
	${SED} ${FILES_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${FILESDIR}/mt-daapd.conf > ${WRKDIR}/mt-daapd.conf
	${INSTALL_DATA} ${WRKDIR}/mt-daapd.conf ${PREFIX}/etc/mt-daapd.conf.sample

.include <bsd.port.mk>

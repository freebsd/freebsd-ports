# ex:ts=8
# Ports collection makefile for:  minicom
# Date created:			  Fri Dec 01, 1995
# Whom:				  obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	minicom
PORTVERSION=	2.00.0
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	anders@FreeBSD.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dfl-baud=57600 \
			--sysconfdir=${PREFIX}/etc/minicom \
			--enable-lock-dir=/var/spool/lock
.if defined(BATCH)
CONFIGURE_ARGS+=	--enable-dfl-port=/dev/cuaa0
.else
CONFIGURE_ARGS+=	--enable-dfl-port=/dev/modem
.endif

MAN1=		minicom.1 runscript.1 ascii-xfr.1

post-patch:
	${MV} ${WRKSRC}/src/rwconf.c ${WRKSRC}/src/rwconf.c.pre_sed
	${SED} -e "s:/usr/local/bin/:${LOCALBASE}/bin/:g" \
		-e "s:/sz:/lsz:g" \
		-e "s:/sb:/lsb:g" \
		-e "s:/sx:/lsx:g" \
		-e "s:/rz:/lrz:g" \
		-e "s:/rb:/lrb:g" \
		-e "s:/rx:/lrx:g" \
		< ${WRKSRC}/src/rwconf.c.pre_sed > ${WRKSRC}/src/rwconf.c

pre-configure:
.if !defined(BATCH)
	# this script creates a link from your comm port to /dev/modem
	${SH} ${SCRIPTDIR}/create-dev-link
.endif

post-install:
	${CHOWN} uucp:dialer ${PREFIX}/bin/minicom
	${CHMOD} 4511 ${PREFIX}/bin/minicom
	${INSTALL} -d -o root -g wheel -m 0755 ${PREFIX}/etc/minicom
.if !exists(${PREFIX}/etc/minicom/minicom.users)
	${INSTALL_DATA} ${WRKSRC}/doc/minicom.users ${PREFIX}/etc/minicom/
.endif
	${CHOWN} uucp ${PREFIX}/etc/minicom
.if !defined(NOPORTDOCS)
	${INSTALL} -d -o root -g wheel -m 0755 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}/
	(umask 022 && cd ${WRKSRC} && ${TAR} --exclude '*/Makefile*' \
		 --exclude '*.orig' -chf - extras doc | ${TAR}  -xf - -C \
		${DOCSDIR})
.endif

.include <bsd.port.mk>

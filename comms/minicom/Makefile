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
MASTER_SITES=	${MASTER_SITE_SUNSITE}  \
		http://www.clinet.fi/~walker/  \
		http://www.pp.clinet.fi/~walker/
MASTER_SITE_SUBDIR=	apps/serialcomm/dialout
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	anders@FreeBSD.org

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dfl-baud=57600 \
			--enable-dfl-port=/dev/modem \
			--sysconfdir=${PREFIX}/etc/minicom
USE_AUTOCONF=	yes

MAN1=		minicom.1 runscript.1 ascii-xfr.1

post-patch:
	${PERL} -pi -e "s@/usr/local/bin/@${LOCALBASE}/bin/@g;s@/sz@/lsz@g; \
		s@/sb@/lsb@g;s@/sx@/lsx@g;s@/rz@/lrz@g;s@/rb@/lrb@g; \
		s@/rx@/lrx@g" ${WRKSRC}/src/rwconf.c

.if !defined(BATCH)
pre-configure:
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

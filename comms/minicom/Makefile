# ex:ts=8
# Ports collection makefile for:  minicom
# Date created:			  Fri Dec 01, 1995
# Whom:				  obrien@cs.ucdavis.edu
#
# $FreeBSD$
#

PORTNAME=	minicom
PORTVERSION=	2.1
CATEGORIES=	comms
MASTER_SITES=	ftp://ftp.nuug.no/pub/anders/distfiles/ \
		http://atreides.freenix.no/~anders/

MAINTAINER=	anders@FreeBSD.org
COMMENT=	An MS-DOS Telix serial communication program "workalike"

RUN_DEPENDS=	lrz:${PORTSDIR}/comms/lrzsz \
		lsz:${PORTSDIR}/comms/lrzsz

WRKSRC=		${WRKDIR}/${DISTNAME:S/.src//}
.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE} \
			--without-included-gettext
PLIST_SUB+=	NLS=""
.endif
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-dfl-baud=57600 \
			--sysconfdir=${PREFIX}/etc/minicom \
			--enable-lock-dir=/var/spool/lock

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 600000
MINICOM_DEFAULT_PORT?=	/dev/cuad0
.else
MINICOM_DEFAULT_PORT?=	/dev/cuaa0
.endif
CONFIGURE_ARGS+=	--enable-dfl-port=${MINICOM_DEFAULT_PORT}

MAN1=		minicom.1 runscript.1 ascii-xfr.1 xminicom.1

post-patch:
	${REINPLACE_CMD} -e "s@/usr/local/bin/@${LOCALBASE}/bin/@; \
		s@/sz@/lsz@;s@/sb@/lsb@;s@/sx@/lsx@;s@/rz@/lrz@; \
		s@/rb@/lrb@;s@/rx@/lrx@" ${WRKSRC}/src/rwconf.c
	${REINPLACE_CMD} -E -e "s@^(SUBDIRS = .*) intl@\1@" \
		${WRKSRC}/Makefile.in

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

.include <bsd.port.post.mk>

# New ports collection makefile for:	bind9-sdb-mysql
# Date created:				6 Sep 2003
# Whom:					Clement Laforet <sheepkiller@cultdeadsheep.org>
#
# $FreeBSD$
#

PORTNAME=	bind9
PORTVERSION=	9.2.3
CATEGORIES=	dns ipv6
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
PKGNAMESUFFIX=	-sdb-mysql
DISTNAME=	bind-${ISCVERSION}
#
# The original patch-files where gotten from:
#	PATCH_SITES=	http://gw.netbastards.org/bm/
#	PATCHFILES=	bind-9.2.2-mysql.patch
# but moved to files/ because it contained hardcoded references to /usr/local
#

MAINTAINER=	clement@FreeBSD.org
COMMENT=	BIND DNS 9 server which supports a MySQL backend

CONFLICTS=	bind-8.3.* bind84-8.4.* bind9-9.2.* bind9-dlz-9.2.* host-* skalibs-0.*

# ISC releases things like 9.2.2rc1, which our versioning doesn't like
ISCVERSION=	9.2.3

DEPRECATED=	Developement has been stopped and it's not yet finished
EXPIRATION_DATE=2004-10-17

USE_MYSQL=	YES
USE_OPENSSL=	YES
USE_REINPLACE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps --disable-threads \
		--with-randomdev=/dev/random --with-openssl=${OPENSSLBASE}

.if defined(PORT_REPLACES_BASE_BIND9)
PKGNAMESUFFIX=	-base
PREFIX=		/usr
BIND_DESTETC=	/etc/namedb
CONFIGURE_ARGS+=	--prefix=${PREFIX} \
			--sysconfdir=${BIND_DESTETC} \
			--mandir=${MANPREFIX}/man
.else
BIND_DESTETC=	${PREFIX}/etc
.endif

PLIST_SUB=	BIND_DESTETC="${BIND_DESTETC}"

MAN1=	dig.1 host.1
MAN3=	lwres.3 lwres_addr_parse.3 lwres_buffer.3 lwres_buffer_add.3 \
	lwres_buffer_back.3 lwres_buffer_clear.3 lwres_buffer_first.3 \
	lwres_buffer_forward.3 lwres_buffer_getmem.3 lwres_buffer_getuint16.3 \
	lwres_buffer_getuint32.3 lwres_buffer_getuint8.3 lwres_buffer_init.3 \
	lwres_buffer_invalidate.3 lwres_buffer_putmem.3 \
	lwres_buffer_putuint16.3 lwres_buffer_putuint32.3 \
	lwres_buffer_putuint8.3 lwres_buffer_subtract.3 lwres_conf_clear.3 \
	lwres_conf_get.3 lwres_conf_init.3 lwres_conf_parse.3 \
	lwres_conf_print.3 lwres_config.3 lwres_context.3 \
	lwres_context_allocmem.3 lwres_context_create.3 \
	lwres_context_destroy.3 lwres_context_freemem.3 \
	lwres_context_initserial.3 lwres_context_nextserial.3 \
	lwres_context_sendrecv.3 lwres_endhostent.3 lwres_endhostent_r.3 \
	lwres_freeaddrinfo.3 lwres_freehostent.3 lwres_gabn.3 \
	lwres_gabnrequest_free.3 lwres_gabnrequest_parse.3 \
	lwres_gabnrequest_render.3 lwres_gabnresponse_free.3 \
	lwres_gabnresponse_parse.3 lwres_gabnresponse_render.3 \
	lwres_gai_strerror.3 lwres_getaddrinfo.3 lwres_getaddrsbyname.3 \
	lwres_gethostbyaddr.3 lwres_gethostbyaddr_r.3 lwres_gethostbyname.3 \
	lwres_gethostbyname2.3 lwres_gethostbyname_r.3 lwres_gethostent.3 \
	lwres_gethostent_r.3 lwres_getipnode.3 lwres_getipnodebyaddr.3 \
	lwres_getipnodebyname.3 lwres_getnamebyaddr.3 lwres_getnameinfo.3 \
	lwres_getrrsetbyname.3 lwres_gnba.3 lwres_gnbarequest_free.3 \
	lwres_gnbarequest_parse.3 lwres_gnbarequest_render.3 \
	lwres_gnbaresponse_free.3 lwres_gnbaresponse_parse.3 \
	lwres_gnbaresponse_render.3 lwres_herror.3 lwres_hstrerror.3 \
	lwres_inetntop.3 lwres_lwpacket_parseheader.3 \
	lwres_lwpacket_renderheader.3 lwres_net_ntop.3 lwres_noop.3 \
	lwres_nooprequest_free.3 lwres_nooprequest_parse.3 \
	lwres_nooprequest_render.3 lwres_noopresponse_free.3 \
	lwres_noopresponse_parse.3 lwres_noopresponse_render.3 \
	lwres_packet.3 lwres_resutil.3 lwres_sethostent.3 \
	lwres_sethostent_r.3 lwres_string_parse.3
MAN5=	rndc.conf.5
MAN8=	dnssec-keygen.8 dnssec-makekeyset.8 dnssec-signkey.8 dnssec-signzone.8 \
	lwresd.8 named-checkconf.8 named-checkzone.8 named.8 nsupdate.8 \
	rndc-confgen.8 rndc.8

WRKSRC=	${WRKDIR}/bind-${ISCVERSION}
post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.8 \
	rndc/rndc.8
	@ ${MV} ${WRKSRC}/bin/${FILE} ${WRKSRC}/bin/${FILE}.Dist
	@ ${SED} -e 's#/etc/named.conf#${BIND_DESTETC}/named.conf#g' \
		-e 's#/etc/rndc.conf#${BIND_DESTETC}/rndc.conf#g' \
		${WRKSRC}/bin/${FILE}.Dist > ${WRKSRC}/bin/${FILE}
.endfor
	${REINPLACE_CMD} -e 's|<malloc\.h>|<stdlib.h>|g' ${WRKSRC}/bin/named/mysqldb.c

post-install:
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${BIND_DESTETC}/rndc.conf.sample
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/arm ${DOCSDIR}/misc
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM*html ${DOCSDIR}/arm
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* ${DOCSDIR}/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/README ${DOCSDIR}/
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>

# New ports collection makefile for:	bind
# Date created:				6 October 2000
# Whom:					will
#
# $FreeBSD$
#

# I stay very aware of developments with BIND in general, and with
# BIND 9 in particular. I frequently delay updating this port from
# a known-stable version due to concerns about stability of a newer
# version. If you are concerned about using the most recent ISC
# release you can generally build it cleanly from the source - Doug

PORTNAME=	bind9
PORTVERSION=	9.2.1
CATEGORIES=	net ipv6
MASTER_SITES=	${MASTER_SITE_ISC} \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/bind9/${ISCVERSION}/,}
MASTER_SITE_SUBDIR=	bind9/${ISCVERSION}
DISTFILES=	bind-9.2.1.tar.gz

MAINTAINER=	DougB@FreeBSD.org

ISCVERSION=	9.2.1

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --disable-linux-caps

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-openssl=${OPENSSLBASE}
.endif

.if ${OSVERSION} > 500030
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

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
DIR=	${WRKSRC}/bin/
post-patch:
.for FILE in check/named-checkconf.8 named/named.8 nsupdate/nsupdate.8 \
	rndc/rndc.8
	@ ${MV} ${DIR}/${FILE} ${DIR}/${FILE}.Dist
	@ ${SED} -e 's#/etc/named.conf#${PREFIX}/etc/named.conf#g' \
		-e 's#/etc/rndc.conf#${PREFIX}/etc/rndc.conf#g' \
		${DIR}/${FILE}.Dist > ${DIR}/${FILE}
.endfor

post-install:
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${PREFIX}/etc/rndc.conf.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM*html \
		${PREFIX}/share/doc/bind9/arm
	${MKDIR} ${PREFIX}/share/doc/bind9/misc
	${INSTALL_DATA} ${WRKSRC}/doc/misc/[a-z]* \
		${PREFIX}/share/doc/bind9/misc
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/README ${PREFIX}/share/doc/bind9/
.endif

.include <bsd.port.post.mk>

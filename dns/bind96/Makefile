# New ports collection makefile for:	bind
# Date created:				6 October 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	bind
PORTVERSION=	9.1.1
CATEGORIES=	net ipv6
MASTER_SITES=	ftp://ftp.isc.org/isc/bind9/${PORTVERSION}/ \
		ftp://ftp.sunet.se/pub/network/isc/bind9/${PORTVERSION}/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,net/bind9/${PORTVERSION}/,}

MAINTAINER=	DougB@FreeBSD.org

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var

MAN1=	dig.1 host.1 named-checkconf.1 named-checkzone.1
MAN5=	rndc.conf.5
MAN8=	lwresd.8 named.8 nsupdate.8 rndc.8 dnssec-keygen.8 dnssec-makekeyset.8 \
	dnssec-signkey.8 dnssec-signzone.8

DIR=	${WRKSRC}/doc/man/bin
post-patch:
.for FILE in named-checkconf.1 named.8 nsupdate.8 rndc.8 rndc.conf.5
	@ ${MV} ${DIR}/${FILE} ${DIR}/${FILE}.Dist
	@ ${SED} -e 's#/etc/named.conf#${PREFIX}/etc/named.conf#g' \
		-e 's#/etc/rndc.conf#${PREFIX}/etc/rndc.conf#g' \
		${DIR}/${FILE}.Dist > ${DIR}/${FILE}
.endfor

	@ ${MV} ${WRKSRC}/doc/man/dnssec/dnssec-signzone.8 \
		${WRKSRC}/doc/man/dnssec/dnssec-signzone.8.Dist
	@ ${SED} -e 's#/etc/named.conf#${PREFIX}/etc/named.conf#g' \
		${WRKSRC}/doc/man/dnssec/dnssec-signzone.8.Dist \
		> ${WRKSRC}/doc/man/dnssec/dnssec-signzone.8

	@ ${MV} ${WRKSRC}/Makefile.in ${WRKSRC}/Makefile.in.Dist
	@ ${SED} -e 's#{INSTALL_PROGRAM}#{INSTALL_DATA} -m 555#g' \
		${WRKSRC}/Makefile.in.Dist > ${WRKSRC}/Makefile.in

post-install:
.for NUM in 1 5 8
	${INSTALL_MAN} ${WRKSRC}/doc/man/bin/*.${NUM} ${MANPREFIX}/man/man${NUM}
.endfor
	${INSTALL_MAN} ${WRKSRC}/doc/man/dnssec/*.8 ${MANPREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/bin/rndc/rndc.conf \
		${PREFIX}/etc/rndc.conf.sample

.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/bind9/arm
	${INSTALL_DATA} ${WRKSRC}/doc/arm/Bv9ARM*html \
		${PREFIX}/share/doc/bind9/arm/
	${CP} -R ${WRKSRC}/doc/misc ${PREFIX}/share/doc/bind9/
	${CP} ${WRKSRC}/CHANGES ${WRKSRC}/COPYRIGHT ${WRKSRC}/FAQ \
		${WRKSRC}/README ${PREFIX}/share/doc/bind9/
.endif

.include <bsd.port.mk>

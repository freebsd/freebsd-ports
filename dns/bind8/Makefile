# New ports collection makefile for:	bind
# Date created:		18 July 1997
# Whom:			jseger@scds.com
#
# $FreeBSD$
#

# I stay very aware of developments regarding BIND. I frequently delay updating
# this port from a known-stable version due to concerns about stability of a
# newer version. If you are interested in using the most recent ISC release
# you can generally build it cleanly from the source. - Doug

PORTNAME=	bind
PORTVERSION=	8.3.0
CATEGORIES?=	net
MASTER_SITES=	ftp://ftp.isc.org/isc/bind/src/${PORTVERSION}/ \
		ftp://ftp.epix.net/pub/isc/bind/src/${PORTVERSION}/ \
		ftp://ftp.nominum.com/pub/isc/bind/src/${PORTVERSION}/ \
		ftp://ftp.grolier.fr/pub/isc/bind/src/${PORTVERSION}/

DISTFILES=	bind-src.tar.gz bind-doc.tar.gz

MAINTAINER=	DougB@FreeBSD.org

WRKSRC=		${WRKDIR}/src

MAN1=		dig.1 dnskeygen.1 dnsquery.1 host.1
MAN3=		getaddrinfo.3 gethostbyname.3 getipnodebyname.3 getnetent.3 \
		getnameinfo.3 inet_cidr.3 hesiod.3 resolver.3 tsig.3
MAN5=		irs.conf.5 named.conf.5 resolver.5
MAN7=		hostname.7 mailaddr.7
MAN8=		named-bootconf.8 named-xfer.8 named.8 ndc.8 nslookup.8 \
		nsupdate.8

PATCH_ARGS=	-d ${WRKDIR}
PATCH_DIST_ARGS=	-d ${WRKDIR}

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKDIR}/doc/man && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} \
		${MAKEFILE} clean all ${INSTALL_TARGET})
	@${MKDIR} ${PREFIX}/share/doc/bind8/html
	${INSTALL_DATA} ${WRKDIR}/doc/html/*.html ${PREFIX}/share/doc/bind8/html
	${CP} -Rp ${WRKDIR}/src/conf ${PREFIX}/share/doc/bind8/
.for file in CHANGES DNSSEC LICENSE LICENSE_RSA README SUPPORT TODO
	${INSTALL_DATA} ${WRKDIR}/src/${file} ${PREFIX}/share/doc/bind8
.endfor
.endif

.include <bsd.port.mk>

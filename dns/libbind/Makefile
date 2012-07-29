# New ports collection makefile for:	libbind
# Date created:				9 August 2009
# Whom:					dougb
#
# $FreeBSD$
#

PORTNAME=	libbind
PORTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	dns net ipv6
MASTER_SITES=	${MASTER_SITE_ISC}
MASTER_SITE_SUBDIR=	libbind/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	dougb@FreeBSD.org
COMMENT=	Standard C resolver library

MAKE_JOBS_UNSAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var --with-randomdev=/dev/random

OPTIONS=	IPV6 "Compile with IPv6 support" on \
		THREADS	"Compile with thread support" on

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !defined(WITHOUT_THREADS)
CONFIGURE_ARGS+=	--enable-threads
.else
CONFIGURE_ARGS+=	--disable-threads
.endif

MAN3=	getaddrinfo.3 gethostbyname.3 getipnodebyname.3 getnameinfo.3 \
	getnetent.3 hesiod.3 inet_cidr.3 resolver.3 tsig.3
MAN5=	resolver.5 irs.conf.5
MAN7=	hostname.7

verify:	checksum
	gpg --verify ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}.asc

post-patch:
.if ${OSVERSION} > 900007
	${CP} ${WRKSRC}/irs/irpmarshall.c ${WRKSRC}/irs/irpmarshall.c.dist
	${SED} -e 's/\#include \<utmp.h\>//' \
		${WRKSRC}/irs/irpmarshall.c.dist > ${WRKSRC}/irs/irpmarshall.c
.endif

.include <bsd.port.post.mk>

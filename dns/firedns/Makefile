# New ports collection makefile for:	firedns
# Date created:		Sun 12 May 22:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firedns
PORTVERSION=	0.9.7
CATEGORIES=	dns devel
MASTER_SITES=	http://firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	A C library for handling asynchronous DNS queries

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring

HAS_CONFIGURE=	yes
CONFIGURE_ENV=	PREFIX="${PREFIX}"
INSTALLS_SHLIB=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN3=		firedns_aton4.3 firedns_aton6.3 \
		firedns_dnsbl_lookup.3 firedns_getip4.3 \
		firedns_getip6.3 firedns_getmx.3 \
		firedns_getmxlist.3 firedns_getname4.3 \
		firedns_getname6.3 firedns_getresult.3 \
		firedns_gettxt.3 firedns_ntoa4.3 \
		firedns_ntoa6.3 firedns_resolveip4.3 \
		firedns_resolveip6.3 firedns_resolvemx.3 \
		firedns_resolvemxlist.3 firedns_resolvename4.3 \
		firedns_resolvename6.3 firedns_resolvetxt.3 \
		libfiredns.3

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.mk>

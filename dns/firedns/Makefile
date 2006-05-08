# New ports collection makefile for:	firedns
# Date created:		Sun 12 May 22:30:00 WST 2002
# Whom:			Dean Hollister <dean@odyssey.apana.org.au>
#
# $FreeBSD$
#

PORTNAME=	firedns
PORTVERSION=	0.9.12
CATEGORIES=	dns devel
MASTER_SITES=	http://www.firestuff.org/projects/ \
		http://www.wa.apana.org.au/~dean/sources/ \
		ftp://ftp.wa.apana.org.au/pub/pc/unix/packages/

MAINTAINER=	dean@odyssey.apana.org.au
COMMENT=	A C library for handling asynchronous DNS queries

BUILD_DEPENDS=	${LOCALBASE}/include/firestring.h:${PORTSDIR}/misc/firestring

USE_BZIP2=	yes
HAS_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
USE_GCC=	3.2+
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		fdnscname.1 fdnsip.1 fdnsip6.1 fdnsip6list.1 fdnsiplist.1 fdnsmx.1 \
		fdnsmxalist.1 fdnsmxlist.1 fdnsname.1 fdnsnamep.1 fdnsspf1.1 \
		fdnstxt.1 fdnstxtlist.1

MAN3=		firedns_aton4.3 firedns_aton6.3 firedns_dnsbl_lookup.3 \
		firedns_free_mxalist.3 firedns_getcname.3 firedns_getip4.3 \
		firedns_getip4list.3 firedns_getip6.3 firedns_getip6list.3 \
		firedns_getmx.3 firedns_getmxlist.3 firedns_getname4.3 \
		firedns_getname6.3 firedns_getresult.3 firedns_gettxt.3 \
		firedns_gettxtlist.3 firedns_ntoa4.3 firedns_ntoa6.3 \
		firedns_resolvecname.3 firedns_resolveip4.3 \
		firedns_resolveip4list.3 firedns_resolveip6.3 \
		firedns_resolveip6list.3 firedns_resolvemx.3 \
		firedns_resolvemxalist.3 firedns_resolvemxlist.3 \
		firedns_resolvename4.3 firedns_resolvename6.3 \
		firedns_resolvetxt.3 firedns_resolvetxtlist.3 \
		libfiredns.3

pre-configure:
	@-${RM} ${WRKSRC}/firemake/*.orig

.include <bsd.port.post.mk>

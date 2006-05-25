# New ports collection makefile for:	QDBM
# Date created:				18 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#    $MCom: ports-stable/databases/qdbm/Makefile,v 1.4 2006/03/04 21:25:54 ahze Exp $

PORTNAME=	qdbm
PORTVERSION=	1.8.57
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://qdbm.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT?=	Quick Database Manager

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

.if !defined(SLAVEPORT)
USE_ICONV=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-iconv
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib"
MAKE_ARGS=	RELCFLAGS="${CFLAGS}" \
		MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}"
INSTALLS_SHLIB=	yes
.if !defined(NOPORTDOCS)
PORTDOCS=	spex.html spex-ja.html ChangeLog NEWS
.endif

MAN1=	cbcodec.1 cbtest.1 crmgr.1 crtest.1 crtsv.1 dpmgr.1 dptest.1 \
	dptsv.1 hvmgr.1 hvtest.1 odidx.1 odmgr.1 odtest.1 rlmgr.1 rltest.1 \
	vlmgr.1 vltest.1 vltsv.1
MAN3=	cabin.3 curia.3 depot.3 hovel.3 odeum.3 qdbm.3 relic.3 villa.3
MLINKS=	curia.3 cropen.3 depot.3 dpopen.3 \
		odeum.3 odopen.3 villa.3 vlopen.3 villa.3 vista.3

OPTIONS=	PTHREAD "Enable pthread support" Off \
		DEBUG "Enable debug" Off

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-build:
	cd ${WRKSRC}/lab; \
	${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" fmtcnv031127

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${PREFIX}/bin

.else

BUILD_DEPENDS+=	qdbm>=${PKGNAME:S/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-//}:${PORTSDIR}/databases/qdbm
LIB_DEPENDS+=	qdbm:${PORTSDIR}/databases/qdbm
RUN_DEPENDS+=	qdbm>=${PKGNAME:S/${PKGNAMEPREFIX}${PORTNAME}${PKGNAMESUFFIX}-//}:${PORTSDIR}/databases/qdbm

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.if ${SLAVEPORT}=="ruby"
	${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/ruby -w|${SETENV} ruby|'
	${FIND} ${WRKSRC} -name '*.bak' | ${XARGS} ${RM} -f
.endif
.endif

.include <bsd.port.pre.mk>

.if !defined(SLAVEPORT)
.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PTHREAD)
CONFIGURE_ARGS+=	--enable-pthread
CFLAGS+=		${PTHREAD_CFLAGS}
.endif
.endif

.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
.if ${PERL_LEVEL} < 500600
IGNORE=	this port requires perl 5.6.0 or later, Install lang/perl5 then try again
.endif
.endif

.include <bsd.port.post.mk>

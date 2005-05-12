# New ports collection makefile for:	QDBM
# Date created:				18 October 2003
# Whom:					Kimura Fuyuki <fuyuki@nigredo.org>
#
# $FreeBSD$
#

PORTNAME=	qdbm
PORTVERSION=	1.8.25
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://qdbm.sourceforge.net/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ahze@FreeBSD.org
COMMENT=	Quick Database Manager

GNU_CONFIGURE=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--enable-zlib \
		--enable-iconv
CONFIGURE_ENV=	CPPFLAGS="${PTHREAD_CFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS}"
MAKE_ARGS=	RELCFLAGS="${CFLAGS}" \
		MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}"
INSTALLS_SHLIB=	yes
.if !defined(NOPORTDOCS)
PORTDOCS=	spex.html spex-ja.html ChangeLog NEWS
.endif

MAN3=		cabin.3 curia.3 depot.3 hovel.3 odeum.3 qdbm.3 relic.3 villa.3
MLINKS=		curia.3 cropen.3 depot.3 dpopen.3 \
		odeum.3 odopen.3 villa.3 vlopen.3 villa.3 vista.3

OPTIONS=	PTHREAD "Enable pthread support" Off \
		DEBUG "Enable debug" Off

.include <bsd.port.pre.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_PTHREAD)
USE_REINPLACE=	yes
CONFIGURE_ARGS+=	--enable-pthread
CFLAGS+=	${PTHREAD_CFLAGS}

post-patch:
	${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure
.endif

post-build:
	cd ${WRKSRC}/lab; \
	${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib -liconv" fmtcnv031127

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${PREFIX}/bin

.include <bsd.port.post.mk>

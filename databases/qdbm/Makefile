# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	qdbm
PORTVERSION=	1.8.78
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/qdbm/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Quick Database Manager

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CFLAGS+=	-fPIC

.if !defined(SLAVEPORT)
USES+=		iconv
CONFIGURE_ARGS=	--enable-zlib \
		--enable-iconv \
		--enable-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-lpthread -L${LOCALBASE}/lib
MAKE_ARGS=	RELCFLAGS="${CFLAGS}" \
		MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}"

PORTDOCS=	ChangeLog NEWS

post-patch:
	@${REINPLACE_CMD} -e 's|@libdir@/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-build:
	(cd ${WRKSRC}/lab && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS} -L${LOCALBASE}/lib ${ICONV_LIB}" \
		fmtcnv031127)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${STAGEDIR}${PREFIX}/bin

.else

LIB_DEPENDS+=	libqdbm.so:${PORTSDIR}/databases/qdbm

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/java|${JAVA_HOME}|' ${WRKSRC}/configure
.if ${SLAVEPORT}=="ruby"
	@${FIND} ${WRKSRC} -type f | \
		${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/ruby -w|${SETENV} ruby|'
	@${FIND} ${WRKSRC} -name '*.bak' | ${XARGS} ${RM} -f
.endif
.endif

.include <bsd.port.pre.mk>

.if !defined(SLAVEPORT) && defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.include <bsd.port.post.mk>

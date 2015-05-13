# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	qdbm
PORTVERSION=	1.8.78
PORTREVISION?=	2
CATEGORIES=	databases
MASTER_SITES=	http://fallabs.com/qdbm/

MAINTAINER=	ports@FreeBSD.org
COMMENT?=	Quick Database Manager

LIB_DEPENDS=	liblzo2.so:${PORTSDIR}/archivers/lzo2

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if !defined(SLAVEPORT)
USES+=		iconv
CONFIGURE_ARGS=	--enable-bzip --enable-lzo --enable-zlib \
		--enable-iconv \
		--enable-pthread
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib
MAKE_ARGS=	MYDATADIR="${DOCSDIR}" MYDOCS="${PORTDOCS}" \
		MYPCDIR="${PREFIX}/libdata/pkgconfig"

PORTDOCS=	ChangeLog NEWS

post-patch:
.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
	@${REINPLACE_CMD} 's/-DNDEBUG//' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} 's/-liconv/${ICONV_LIB}/' ${WRKSRC}/configure

post-build:
	(cd ${WRKSRC}/lab && ${MAKE} CC="${CC}" CFLAGS="${CFLAGS}" \
		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		fmtcnv031127)

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lab/fmtcnv031127 ${STAGEDIR}${PREFIX}/bin

.else

LIB_DEPENDS+=	libqdbm.so:${PORTSDIR}/databases/qdbm

post-patch:
.if defined(WITH_DEBUG) && !defined(WITHOUT_DEBUG)
	@${REINPLACE_CMD} 's/-DNDEBUG//' ${WRKSRC}/Makefile.in
.endif
	@${REINPLACE_CMD} -e 's/-liconv//' -e 's/-lstdc++//' ${WRKSRC}/configure
.if ${SLAVEPORT} == "ruby"
	@${REINPLACE_CMD} '/iconv/d' ${WRKSRC}/curia/extconf.rb \
		${WRKSRC}/depot/extconf.rb ${WRKSRC}/villa/extconf.rb
.endif

.endif # !defined(SLAVEPORT)

.include <bsd.port.mk>

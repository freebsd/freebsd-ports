PORTNAME=	pbzip2
DISTVERSION=	1.1.13
CATEGORIES=	archivers
MASTER_SITES=	https://launchpad.net/${PORTNAME}/1.1/${DISTVERSION}/+download/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Parallel BZIP2
WWW=		https://launchpad.net/pbzip2/

LICENSE=	BSD4CLAUSE

MAKE_ARGS=	CFLAGS="${CXXFLAGS}" CC="${CXX}"

PLIST_FILES=	bin/pbzip2 bin/pbunzip2 \
		share/man/man1/pbzip2.1.gz share/man/man1/pbunzip2.1.gz

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's,PRI[iu]MAX, & ,g' ${WRKSRC}/pbzip2.cpp \
		${WRKSRC}/BZ2StreamScanner.cpp
.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1500053
# Spell target sources to be understood by both BSD and GNU make(1)
	@${REINPLACE_CMD} -e '/-O2/s,^,#, ; s,$$^,$$>&,' \
		${WRKSRC}/Makefile
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/pbunzip2
	${INSTALL_MAN} ${WRKSRC}/pbzip2.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${LN} -sf pbzip2.1 ${STAGEDIR}${PREFIX}/share/man/man1/pbunzip2.1

.include <bsd.port.mk>

# Created by: ijliao
# $FreeBSD$

PORTNAME=	pbzip2
PORTVERSION=	1.1.13
CATEGORIES=	archivers
MASTER_SITES=	http://launchpad.net/${PORTNAME}/1.1/${PORTVERSION}/+download/

MAINTAINER=	farrokhi@FreeBSD.org
COMMENT=	Parallel BZIP2

LICENSE=	BSD4CLAUSE

MAKE_ARGS=	CFLAGS="${CXXFLAGS}" CC="${CXX}"

PLIST_FILES=	bin/pbzip2 bin/pbunzip2 \
		share/man/man1/pbzip2.1.gz share/man/man1/pbunzip2.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's,PRI[iu]MAX, & ,g' ${WRKSRC}/pbzip2.cpp \
		${WRKSRC}/BZ2StreamScanner.cpp
# Spell target sources to be understood by both BSD and GNU make(1)
	@${REINPLACE_CMD} -e '/-O2/s,^,#, ; s,$$^,$$>&,' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${LN} -sf ${PORTNAME} ${STAGEDIR}${PREFIX}/bin/pbunzip2
	${INSTALL_MAN} ${WRKSRC}/pbzip2.1 ${STAGEDIR}${PREFIX}/share/man/man1/
	${LN} -sf pbzip2.1 ${STAGEDIR}${PREFIX}/share/man/man1/pbunzip2.1

.include <bsd.port.mk>

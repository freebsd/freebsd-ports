PORTNAME=	packddir
PORTVERSION=	0.0.6
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH
DISTNAME=	upackddir_${PORTVERSION}-1

MAINTAINER=	ayu@commun.jp
COMMENT=	Utilities to unpack and create PackdDir archives
WWW=		https://www.nongnu.org/packddir/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/upackddir \
		share/man/man1/upackddir.1.gz
MAKE_ARGS=	CC="${CC}"

post-patch:
	${REINPLACE_CMD} -e 's|$$(DESTDIR)/usr|$$(DESTDIR)${PREFIX}|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/upackddir.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/upackddir

.include <bsd.port.mk>

# Created by: Ayumi M <ayu@commun.jp>
# $FreeBSD$

PORTNAME=	packddir
PORTVERSION=	0.0.6
CATEGORIES=	archivers
MASTER_SITES=	SAVANNAH
DISTNAME=	upackddir_${PORTVERSION}-1

MAINTAINER=	ayu@commun.jp
COMMENT=	These trivial utilities can unpack and create PackdDir archives

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/src

PLIST_FILES=	bin/upackddir \
		man/man1/upackddir.1.gz
MAKE_ARGS=	CC="${CC}"

post-patch:
	${REINPLACE_CMD} -e 's|$$(DESTDIR)/usr|$$(DESTDIR)${PREFIX}|' ${WRKSRC}/Makefile

post-install:
	${INSTALL_MAN} ${WRKSRC}/upackddir.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/upackddir

.include <bsd.port.mk>

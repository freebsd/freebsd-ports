PORTNAME=	celvis
PORTVERSION=	1.3
CATEGORIES=	chinese editors
MASTER_SITES=	http://ftp.ist.utl.pt/pub/ctan/language/chinese/chtex/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vi/ex clone that speaks Chinese

DEPRECATED=	Last upstream release was in 2001
EXPIRATION_DATE=	2024-01-16

USES=		ncurses

MAKE_ARGS=	LIBS="${LDFLAGS} -lncurses"

CFLAGS+=	-Wno-error=return-type

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

do-install:
	@# install target in celvis Makefile is not too good -- this is easier
	${INSTALL_PROGRAM} ${WRKSRC}/celvis ${WRKSRC}/virec ${STAGEDIR}${PREFIX}/bin
	${LN} -s celvis ${STAGEDIR}${PREFIX}/bin/cvi
	${INSTALL_MAN} ${FILESDIR}/celvis.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

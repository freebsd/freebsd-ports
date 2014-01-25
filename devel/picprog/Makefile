# Created by: Johan Kerckaert <kirk@bricsnet.com>
# $FreeBSD$

PORTNAME=	picprog
PORTVERSION=	1.9.1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Serial port pic16c84 programmer

OPTIONS_DEFINE=	DOCS

USES=		gmake

PLIST_FILES=	bin/picprog \
		man/man1/picprog.1.gz

PORTDOCS=	README anybrowser3.png jdm84ne3.png jdm84pcb6.png picprog.html

.for a in ia64 powerpc sparc64
BROKEN_${a}=		Does not compile on ia64, powerpc, or sparc64
.endfor

post-patch:
	@${REINPLACE_CMD} -e 's|^CXX=.*||; s|^CXXFLAGS=.*||; s|^LDFLAGS=.*||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprog ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picprog.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in README *.png picprog.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor


.include <bsd.port.mk>

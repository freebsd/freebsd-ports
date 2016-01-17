# Created by: Johan Kerckaert <kirk@bricsnet.com>
# $FreeBSD$

PORTNAME=	picprog
PORTVERSION=	1.9.1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Serial port pic16c84 programmer

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

OPTIONS_DEFINE=	DOCS

USES=		gmake

PLIST_FILES=	bin/picprog \
		man/man1/picprog.1.gz

PORTDOCS=	README anybrowser3.png jdm84ne3.png jdm84pcb6.png picprog.html

ONLY_FOR_ARCHS=	i386 amd64
ONLY_FOR_ARCHS_REASON=	uses x86 assembly

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

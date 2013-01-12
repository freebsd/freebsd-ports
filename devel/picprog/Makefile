# Created by: Johan Kerckaert <kirk@bricsnet.com>
# $FreeBSD$

PORTNAME=	picprog
PORTVERSION=	1.9.1
CATEGORIES=	devel
MASTER_SITES=	http://hyvatti.iki.fi/~jaakko/pic/

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Serial port pic16c84 programmer

USE_GMAKE=	yes

PLIST_FILES=	bin/picprog
MAN1=		picprog.1

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	README anybrowser3.png jdm84ne3.png jdm84pcb6.png picprog.html
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|^CXX=.*||; s|^CXXFLAGS=.*||; s|^LDFLAGS=.*||' \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/picprog ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/picprog.1 ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in README *.png picprog.html
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.if ${ARCH} == "ia64" || ${ARCH} == "powerpc" || ${ARCH} == "sparc64"
BROKEN=		Does not compile on ia64, powerpc, or sparc64
.endif

.include <bsd.port.post.mk>

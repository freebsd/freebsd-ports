PORTNAME=	kermit
DISTVERSION=	10.0-beta04
CATEGORIES=	comms ftp net
MASTER_SITES=	https://www.kermitproject.org/ftp/kermit/test/tar/ \
		ftp://ftp.kermitproject.org/kermit/test/tar/
DISTNAME=	cku${DISTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable scriptable network and serial communication program

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

USES=		ssl
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd+ssl
MAKE_ARGS=	CC2="${CC}" SSLINC="-I${OPENSSLINC}" SSLLIB="-L${OPENSSLLIB}"

PLIST_FILES=	bin/kermit man/man1/kermit.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's,-O2 -pipe,${CFLAGS},' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${STAGEDIR}${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${STAGEDIR}${MANPREFIX}/man/man1/kermit.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

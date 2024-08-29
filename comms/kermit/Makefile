PORTNAME=	kermit
PORTVERSION=	10.0.beta11
CATEGORIES=	comms ftp net
MASTER_SITES=	https://www.kermitproject.org/ftp/kermit/test/tar/ \
		ftp://ftp.kermitproject.org/kermit/test/tar/
DISTNAME=	cku414-${PORTVERSION:E}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable scriptable network and serial communication program
WWW=		https://www.kermitproject.org/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING.TXT

USES=		ssl
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd+ssl
MAKE_ARGS=	CC="${CC}" CC2="${CC}" \
		SSLINC="-I${OPENSSLINC}" SSLLIB="-L${OPENSSLLIB}"

PLIST_FILES=	bin/kermit share/man/man1/kermit.1.gz
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's^-O2 -pipe^${CFLAGS}^' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${STAGEDIR}${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${STAGEDIR}${PREFIX}/share/man/man1/kermit.1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.TXT ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

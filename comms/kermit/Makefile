# Created by: Paul Traina <pst@FreeBSD.org>
# $FreeBSD$

PORTNAME=	kermit
PORTVERSION=	9.0.302
CATEGORIES=	comms ftp net
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.icm.edu.pl/pub/kermit/archives/
DISTNAME=	cku${PORTVERSION:E}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Portable scriptable network and serial communication program

LICENSE=	BSD

USE_OPENSSL=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd+ssl
MAKE_ARGS=	CC2="${CC}" SSLINC="-I${OPENSSLINC}" SSLLIB="-L${OPENSSLLIB}"

PLIST_FILES=	bin/kermit man/man1/kermit.1.gz
PORTDOCS=	*
PORTEXAMPLES=	*

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's,-O2 -pipe,${CFLAGS},' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${STAGEDIR}${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr \
		${STAGEDIR}${MANPREFIX}/man/man1/kermit.1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${STAGEDIR}${DOCSDIR}
	${LN} -sf ckaaaa.txt ${STAGEDIR}${DOCSDIR}/READ.ME
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ckermit.ini \
		${STAGEDIR}${EXAMPLESDIR}/dot.kermrc
	${INSTALL_DATA} ${WRKSRC}/ckermod.ini \
		${STAGEDIR}${EXAMPLESDIR}/dot.mykermrc

.include <bsd.port.mk>

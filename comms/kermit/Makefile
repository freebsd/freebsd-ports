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
MAKE_ARGS=	CC2=${CC} SSLINC=-I${OPENSSLINC} SSLLIB=-L${OPENSSLLIB}

PLIST_FILES=	bin/kermit
PORTDOCS=	*
PORTEXAMPLES=	*
MAN1=		kermit.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's,-O2 -pipe,${CFLAGS},' ${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${MANPREFIX}/man/man1/kermit.1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.txt ${DOCSDIR}
	${LN} -sf ckaaaa.txt ${DOCSDIR}/READ.ME
.endif
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ckermit.ini ${EXAMPLESDIR}/dot.kermrc
	${INSTALL_DATA} ${WRKSRC}/ckermod.ini ${EXAMPLESDIR}/dot.mykermrc
.endif

.include <bsd.port.mk>

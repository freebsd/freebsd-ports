# New ports collection makefile for:	C-Kermit
# Date created:				Oct 27, 1994
# Whom:					Paul Traina <pst@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kermit
PORTVERSION=	9.0.301
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.icm.edu.pl/pub/kermit/archives/
DISTNAME=	cku${PORTVERSION:E}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Combined network and serial communication package

LICENSE=	BSD

USE_OPENSSL=	yes
NO_WRKSUBDIR=	yes
MAKEFILE=	makefile
ALL_TARGET=	freebsd+ssl
MAKE_ARGS=	CC2=${CC} SSLINC=-I${OPENSSLINC} SSLLIB=-L${OPENSSLLIB}
CFLAGS+=	-DHERALD=\\\"\\\\\\\" ${HERALD}\\\\\\\"\\\"

PLIST_FILES=	bin/kermit
PORTDOCS=	*
PORTEXAMPLES=	*
MAN1=		kermit.1

.include <bsd.port.pre.mk>

# Explicitly pass version of our beloved OS until upstream code is fixed
HERALD!=	${UNAME} -sr

post-patch:
	@${REINPLACE_CMD} -e 's,-O -pipe,${CFLAGS},' ${WRKSRC}/${MAKEFILE}
# Catch up with recent <utmp.h> replacement by <utmpx.h>
.if ${OSVERSION} > 900006
	@${REINPLACE_CMD} -e 's,ut\.ut_name,ut.ut_user,g' \
		-e 's,UNIXWARE,FREEBSD4,' ${WRKSRC}/ckufio.c
.endif

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

.include <bsd.port.post.mk>

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
ALL_TARGET=	krbmit

PLIST_FILES=	bin/kermit
PORTDOCS=	*
PORTEXAMPLES=	*
MAN1=		kermit.1

MAKE_ARGS=	KTARGET=freebsd CC="${CC}" CC2="${CC}" \
		CFLAGS="${CFLAGS} -I${OPENSSLINC} -DBSD44 \
		-DCK_NCURSES -DCK_NEWTERM -DHERALD=\"\\\" ${HERALD}\\\"\" \
		-DTCPSOCKET -DNOCOTFMC -DFREEBSD4 -DUSE_UU_LOCK -DFNFLOAT \
		-funsigned-char -DTPUTSARGTYPE=int -DUSE_STRERROR -DCKHTTP \
		-DCK_SSL -DCK_AUTHENTICATION -DCK_ENCRYPTION -DCK_DES \
		-DOPENSSL_DES_LIBDES_COMPATIBILITY -DOPENSSL_097" \
		LIBS="-L${OPENSSLLIB} \
		-lssl -lcrypto -lncurses -lcrypt -lutil -lm"

.include <bsd.port.pre.mk>

# Explicitly pass version of our beloved OS; upstream routine is not robust
# enough to handle all cases correctly
HERALD!=	${UNAME} -sr | ${CUT} -d - -f 1

post-patch:
# Catch up with recent <utmp.h> replacement by <utmpx.h>
.if ${OSVERSION} > 900006
	@${REINPLACE_CMD} -e 's,ut\.ut_name,ut.ut_user,g' \
		-e 's,UNIXWARE,FREEBSD4,' ${WRKSRC}/ckufio.c
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/krbmit ${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${PREFIX}/man/man1/kermit.1
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

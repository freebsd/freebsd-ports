# New ports collection makefile for:	kermit
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	kermit
PORTVERSION=	8.0.200
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.icm.edu.pl/pub/kermit/archives/
DISTNAME=	cku200

MAINTAINER=	naddy@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		kermit.1

MAKEFILE=	makefile
ALL_TARGET=	xermit
MAKE_ARGS=	KTARGET=freebsd \
		CFLAGS="${CFLAGS} -DBSD44 -DCK_NCURSES -DCK_NEWTERM \
		-DTCPSOCKET -DNOCOTFMC -DFREEBSD4 -DUSE_UU_LOCK -DFNFLOAT \
		-funsigned-char -DTPUTSARGTYPE=int -DUSE_STRERROR" \
		LIBS="-lncurses -lcrypt -lutil -lm"

DOCDIR=		${PREFIX}/share/doc/kermit
EXAMPLESDIR=	${PREFIX}/share/examples/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${PREFIX}/man/man1/kermit.1
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ckaaaa.txt ${DOCDIR}/READ.ME
	@for file in COPYING.TXT ckcbwr.txt ckccfg.txt ckcplm.txt \
	    ckermit70.txt ckermit80.txt ckubwr.txt ckuins.txt ckututor.txt; \
	do \
	    ${ECHO} "Installing ${DOCDIR}/$${file} ..." ; \
	    ${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ckermit.ini ${EXAMPLESDIR}/dot.kermrc
	${INSTALL_DATA} ${WRKSRC}/ckermod.ini ${EXAMPLESDIR}/dot.mykermrc

.include <bsd.port.mk>

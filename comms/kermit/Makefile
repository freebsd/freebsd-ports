# New ports collection makefile for:	kermit
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	kermit
PORTVERSION=	7.0.197
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/ \
		ftp://ftp.icm.edu.pl/pub/kermit/archives/
DISTNAME=	cku197

MAINTAINER=	joerg@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		kermit.1

MAKEFILE=	makefile
ALL_TARGET=	xermit
MAKE_ARGS=	KTARGET=freebsd \
		CFLAGS="${CFLAGS} -DBSD44 -DCK_CURSES -DCK_NEWTERM \
		-DTCPSOCKET -DNOCOTFMC -DFNFLOAT -DUSE_STRERROR \
		-DFREEBSD4 -DUSE_UU_LOCK" \
		LIBS="-lncurses -lcrypt -lutil -lm"

DOCDIR=		${PREFIX}/share/doc/kermit
EXAMPLESDIR=	${PREFIX}/share/examples/kermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/wermit ${PREFIX}/bin/kermit
	${INSTALL_MAN} ${WRKSRC}/ckuker.nr ${PREFIX}/man/man1/kermit.1
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/ckaaaa.txt ${DOCDIR}/READ.ME
	@for file in ckuaaa.txt ckermit2.txt ckcbwr.txt ckubwr.txt \
	    ckuins.txt telnet.txt security.txt iksd.txt ckcplm.txt \
	    ckccfg.txt ; \
	do \
	    ${ECHO} "Installing ${DOCDIR}/$${file} ..." ; \
	    ${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR}; \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@set -- \
	    ckermit.ini dot.kermrc \
	    ckermod.ini dot.mykermrc \
	    ckurzsz.ini dot.rzszkermrc \
	    ckermit.kdd dot.kdd \
	    ckermit.knd dot.knd \
	    ckermit.ksd dot.ksd \
	    ckedemo.ksc ckedemo.ksc \
	    ckepage.ksc ckepage.ksc \
	    ckevt.ksc ckevt.ksc \
	    iksdpy iksdpy ; \
	while [ $$# -gt 1 ] ; \
	do \
	    file=$$1; dst=$$2 ; shift ; shift ; \
	    ${ECHO} "Installing $${file} as ${EXAMPLESDIR}/$${dst} ..." ; \
	    ${INSTALL_DATA} ${WRKSRC}/$${file} ${EXAMPLESDIR}/$${dst}; \
	done

.include <bsd.port.mk>

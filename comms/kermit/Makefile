# New ports collection makefile for:	kermit
# Date created:		Oct 27, 1994
# Whom:			pst
#
# $FreeBSD$
#

PORTNAME=	kermit
PORTVERSION=	7.0.196
CATEGORIES=	comms
MASTER_SITES=	ftp://kermit.columbia.edu/kermit/archives/
DISTNAME=	cku196

MAINTAINER=	joerg@FreeBSD.org

NO_WRKSUBDIR=	yes
MAN1=		kermit.1
MANCOMPRESSED=	yes

post-install:
	@${MKDIR} ${PREFIX}/share/examples/kermit
	@${MKDIR} ${PREFIX}/share/doc/kermit
	${INSTALL_DATA} ${WRKSRC}/ckaaaa.txt ${PREFIX}/share/doc/kermit/READ.ME
	@for file in ckuaaa.txt ckermit2.txt ckcbwr.txt ckubwr.txt \
	  ckuins.txt telnet.txt security.txt iksd.txt ckcplm.txt \
	  ckccfg.txt ; \
	do \
	    echo Installing ${PREFIX}/share/doc/kermit/$${file} ... ; \
	    ${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/share/doc/kermit/; \
	done
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
	    echo Installing $${file} as ${PREFIX}/share/examples/kermit/$${dst} ... ; \
	    ${INSTALL_DATA} ${WRKSRC}/$${file} ${PREFIX}/share/examples/kermit/$${dst}; \
	done

.include <bsd.port.mk>

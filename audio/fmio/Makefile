# New ports collection makefile for:	fmio
# Date created:				10 Feb 2001
# Whom:					Den Ivanov <d.s.div@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	fmio
PORTVERSION=	1.2.29
CATEGORIES=	audio
MASTER_SITES=	http://www.jumbo.narod.ru/src/fmio/ \
		http://www.tele2.chel.ru/~pva/src/fmio/

MAINTAINER=	kunia@istc.kiev.ua

MAN1=		fmio.1
MANCOMPRESSED=	no

post-patch:
	@${SED} -e 's,machine/soundcard.h,sys/soundcard.h,' < \
		${WRKSRC}/mixer.c > ${WRKSRC}/mixer.c.new
	@${MV} ${WRKSRC}/mixer.c.new ${WRKSRC}/mixer.c

pre-build:
.if !defined(WITH_BKTR)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Highway Xtreme support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BKTR=yes\""
	@${ECHO_MSG}
.endif

post-build:
.if defined(WITH_BKTR)
	@${MAKE} ${WRKSRC}/utils/bktrctl
.endif

do-install:
.if defined(WITH_BKTR)
	${INSTALL_PROGRAM} ${WRKSRC}/utils/bktrctl ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/bktrctl.sh ${PREFIX}/etc/rc.d
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/fmio ${PREFIX}/bin
	${CHMOD} 4555 ${PREFIX}/bin/fmio
	${INSTALL_MAN} ${WRKSRC}/fmio.1 ${MANPREFIX}/man/man1
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Changelog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/FAQ.ru ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}

post-install:
.if !defined(WITH_BKTR)
	${GREP} -v "bktrctl.sh" ${TMPPLIST} > ${TMPPLIST}.tmp
	${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
.endif

.include <bsd.port.mk>

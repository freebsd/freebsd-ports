# New ports collection makefile for:	fmio
# Date created:				10 Feb 2001
# Whom:					Den Ivanov <d.s.div@bigfoot.com>
#
# $FreeBSD$
#

PORTNAME=	fmio
PORTVERSION=	1.2.25
CATEGORIES=	audio
MASTER_SITES=	http://www.jumbo.narod.ru/src/fmio/

MAINTAINER=	kunia@istc.kiev.ua

MAN1=		fmio.1
MANCOMPRESSED=	no

pre-build:
.if !defined(WITH_XTREME)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Highway Xtreme support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_XTREME=yes\""
	@${ECHO_MSG}
.endif

post-build:
.if defined(WITH_XTREME)
	@${MAKE} ${WRKSRC}/utils/bktrctl
.endif

do-install:
.if defined(WITH_XTREME)
	${INSTALL} ${WRKSRC}/utils/bktrctl ${PREFIX}/bin
	${INSTALL} ${FILESDIR}/bktrctl.sh ${PREFIX}/etc/rc.d
.endif
	${INSTALL} -m 4555 ${WRKSRC}/fmio ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/fmio.1 ${MANPREFIX}/man/man1

post-install:
.if !defined(WITH_XTREME)
	${GREP} -v "bktrctl.sh" ${TMPPLIST} > ${TMPPLIST}.tmp
	${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
.endif

.include <bsd.port.mk>

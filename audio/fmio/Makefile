# Created by: Den Ivanov <d.s.div@bigfoot.com>
# $FreeBSD$

PORTNAME=	fmio
PORTVERSION=	2.0.8
CATEGORIES=	audio
MASTER_SITES=	http://www.aliasnet.ru/~pva/src/fmio/ \
		http://www.jumbo.narod.ru/src/fmio/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	FM radio card manipulation utility

DEPRECATED=	No more public distfiles
EXPIRATION_DATE=	2014-03-07

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/${DISTNAME}/src

OPTIONS_DEFINE=	DOCS

pre-build:
.if !defined(WITH_BKTR)
	@${ECHO_MSG}
	@${ECHO_MSG} "If you want to compile with Highway Xtreme support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BKTR=yes\""
	@${ECHO_MSG}
.endif

post-build:
.if defined(WITH_BKTR)
	@cd ${WRKSRC}/../utils && ${MAKE} bktrctl
.endif

do-install:
.if defined(WITH_BKTR)
	${INSTALL_PROGRAM} ${WRKSRC}/../utils/bktrctl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/bktrctl.sh ${STAGEDIR}${PREFIX}/etc/rc.d
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/fmio ${STAGEDIR}${PREFIX}/bin
	${CHMOD} 4555 ${STAGEDIR}${PREFIX}/bin/fmio
	${INSTALL_MAN} ${WRKSRC}/fmio.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../Changelog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/FAQ ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/../doc/FAQ.ru ${STAGEDIR}${DOCSDIR}

post-install:
.if !defined(WITH_BKTR)
	${GREP} -v "bktrctl.sh" ${TMPPLIST} > ${TMPPLIST}.tmp
	${MV} -f ${TMPPLIST}.tmp ${TMPPLIST}
.endif

.include <bsd.port.mk>

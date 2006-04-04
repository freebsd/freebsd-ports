# New ports collection makefile for:	maradns
# Date created:				26 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	maradns
PORTVERSION=	1.2.07.1
CATEGORIES=	dns
MASTER_SITES=	http://www.maradns.org/download/1.2/${PORTVERSION}/ \
		http://kapranoff.ru/~kappa/files/

MAINTAINER=	alex@kapranoff.ru
COMMENT=	DNS server with focus on security and simplicity

REINPLACE_ARGS=	-i ""
USE_BZIP2=	yes
MAKE_ENV=	FLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

USE_RC_SUBR=	yes
RC_SCRIPTS_SUB=	PREFIX=${PREFIX} \
		RC_SUBR=${RC_SUBR}

MAN1=	askmara.1 getzone.1 fetchzone.1
MAN5=	mararc.5 csv1.5 csv2.5 csv2_txt.5
MAN8=	maradns.8 zoneserver.8 duende.8
#MANLANG=	"" fr.ISO8859-1

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/mara|${PREFIX}/etc/mara|g'
	@${FIND} ${WRKSRC} -name '*Makefile*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/getzone ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/fetchzone ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tcp/zoneserver ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/tools/duende ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/askmara.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/getzone.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/fetchzone.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/maradns.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/zoneserver.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/duende.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/mararc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv1.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/csv2_txt.5 ${MANPREFIX}/man/man5
#	@${MKDIR} ${MANPREFIX}/man/fr.ISO8859-1/man1
#	@${MKDIR} ${MANPREFIX}/man/fr.ISO8859-1/man5
#	@${MKDIR} ${MANPREFIX}/man/fr.ISO8859-1/man8
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/askmara.1 ${MANPREFIX}/man/fr.ISO8859-1/man1
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/getzone.1 ${MANPREFIX}/man/fr.ISO8859-1/man1
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/csv1.5 ${MANPREFIX}/man/fr.ISO8859-1/man5
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/mararc.5 ${MANPREFIX}/man/fr.ISO8859-1/man5
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/maradns.8 ${MANPREFIX}/man/fr.ISO8859-1/man8
#	${INSTALL_MAN} ${WRKSRC}/doc/fr/man/zoneserver.8 ${MANPREFIX}/man/fr.ISO8859-1/man8
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc \
 		${PREFIX}/etc/mararc.sample
	${MKDIR} ${PREFIX}/etc/maradns
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 \
 		${PREFIX}/etc/maradns/example_csv2
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
 		'-e s!%%SERVICE%%!maradns!g' \
 		${FILESDIR}/rc_d.sh > ${PREFIX}/etc/rc.d/maradns.sh
	@${SED} ${RC_SCRIPTS_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
 		'-e s!%%SERVICE%%!zoneserver!g' \
 		${FILESDIR}/rc_d.sh > ${PREFIX}/etc/rc.d/zoneserver.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/maradns.sh
	@${CHMOD} 755 ${PREFIX}/etc/rc.d/zoneserver.sh
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/* \
 		${EXAMPLESDIR}
	@${MKDIR} ${EXAMPLESDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/examples/* \
 		${EXAMPLESDIR}/fr
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.* \
 		${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/QuickStart \
 		${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/README \
 		${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/misc ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/pdf ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/tutorial ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/text ${DOCSDIR}/en
	@${MKDIR} ${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/*.* \
 		${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/QuickStart \
 		${DOCSDIR}/fr
	${CP} -R ${WRKSRC}/doc/fr/tutorial ${DOCSDIR}/fr
.endif

.include <bsd.port.mk>

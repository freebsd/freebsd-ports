# New ports collection makefile for:	maradns
# Date created:				26 May 2001
# Whom:					Anders Nordby <anders@fix.no>
#
# $FreeBSD$
#

PORTNAME=	maradns
PORTVERSION=	1.0.21
CATEGORIES=	dns
MASTER_SITES=	http://www.maradns.org/download/ \
		http://maradns.glou.net/download/ \
		http://maradns.3va.net/download/

MAINTAINER=	clement@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

USE_REINPLACE=	yes
REINPLACE_ARGS=	-i ""
USE_BZIP2=	yes
MAKE_ENV=	FLAGS="${CFLAGS} ${PTHREAD_CFLAGS}"

MAN1=	askmara.1 getzone.1
MAN5=	mararc.5
MAN8=	maradns.8 zoneserver.8

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/mara|${PREFIX}/etc/mara|g'
	@${FIND} ${WRKSRC} -name '*Makefile*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g ; \
		 s|-lpthread|${PTHREAD_LIBS}|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tools/askmara ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/server/maradns ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/getzone ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tuzona/zoneserver ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_mararc \
		${PREFIX}/etc/mararc.sample
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/askmara.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/getzone.1 ${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/mararc.5 ${MANPREFIX}/man/man5
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/maradns.8 ${MANPREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/doc/en/man/zoneserver.8 ${MANPREFIX}/man/man8
	${INSTALL_SCRIPT} ${FILESDIR}/maradns.sh.sample ${PREFIX}/etc/rc.d
.ifndef(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/00README.FIRST ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO.* ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/QuickStart ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/README ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/faq.* ${DOCSDIR}/en
	@${MKDIR} ${DOCSDIR}/en/examples
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_* \
		${DOCSDIR}/en/examples
	@${MKDIR} ${DOCSDIR}/en/misc
	${INSTALL_DATA} ${WRKSRC}/doc/en/misc/0README ${DOCSDIR}/en/misc
	${INSTALL_DATA} ${WRKSRC}/doc/en/misc/recursive-case-insensitive \
		${DOCSDIR}/en/misc
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.* ${DOCSDIR}/en/misc
	@${MKDIR} ${DOCSDIR}/en/misc/spammers
	${INSTALL_DATA} ${WRKSRC}/doc/en/misc/spammers/*.* \
		${DOCSDIR}/en/misc/spammers
	@${MKDIR} ${DOCSDIR}/en/misc/spammers/hiddenonline
	${INSTALL_DATA} ${WRKSRC}/doc/en/misc/spammers/hiddenonline/*.* \
		${DOCSDIR}/en/misc/spammers/hiddenonline
	@${MKDIR} ${DOCSDIR}/en/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/en/tutorial/*.* ${DOCSDIR}/en/tutorial
	@${MKDIR} ${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/QuickStart ${DOCSDIR}/fr
	${INSTALL_DATA} ${WRKSRC}/doc/fr/faq.* ${DOCSDIR}/fr
	@${MKDIR} ${DOCSDIR}/fr/tutorial
	${INSTALL_DATA} ${WRKSRC}/doc/fr/tutorial/*.* ${DOCSDIR}/fr/tutorial
.endif

.include <bsd.port.mk>

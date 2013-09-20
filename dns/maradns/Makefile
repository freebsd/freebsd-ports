# Created by: Anders Nordby <anders@fix.no>
# $FreeBSD$

PORTNAME=	maradns
PORTVERSION=	1.4.12
CATEGORIES=	dns
MASTER_SITES=	http://www.maradns.org/download/1.4/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DNS server with focus on security and simplicity

LICENSE=	BSD
LICENSE_FILE=	${WRKSRC}/COPYING

REINPLACE_ARGS=	-i ""
MAKE_ENV=	FLAGS="${CFLAGS}"
CONFIGURE_ENV=	LANG=

USE_BZIP2=	yes
USE_RC_SUBR=	${PORTNAME} zoneserver
USERS=		bind
GROUPS=		bind

MAN1=		askmara.1 getzone.1 fetchzone.1
MAN5=		mararc.5 csv1.5 csv2.5 csv2_txt.5
MAN8=		maradns.8 zoneserver.8 duende.8

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|/etc/maradns|${ETCDIR}|g; s|/etc/mararc|${ETCDIR}|g'
	@${FIND} ${WRKSRC} -name '*Makefile*' | ${XARGS} ${REINPLACE_CMD} -e \
		's|make|\$$\{MAKE\}|g ; \
		 s|^FLAGS =|#FLAGS =|g'

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

	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_full_mararc ${PREFIX}/etc/mararc.sample

	${MKDIR} ${ETCDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/example_csv2 ${ETCDIR}/example_csv2
	${MKDIR} ${ETCDIR}/logger

.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_DATA} ${WRKSRC}/doc/en/examples/* ${EXAMPLESDIR}/
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/*.* ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/QuickStart ${DOCSDIR}/en
	${INSTALL_DATA} ${WRKSRC}/doc/en/README ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/misc ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/pdf ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/tutorial ${DOCSDIR}/en
	${CP} -R ${WRKSRC}/doc/en/text ${DOCSDIR}/en
.endif

.include <bsd.port.mk>

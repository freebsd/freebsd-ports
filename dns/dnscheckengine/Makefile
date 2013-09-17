# Created by: dnscheckengine-port@academ.com (Stan Barber)
# $FreeBSD$

PORTNAME=	dnscheckengine
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://www.ns.gen.tx.us/pub/software/dnscheck-se/
DISTNAME=	DNSCheck-1.1

MAINTAINER=	dnscheckengine-port@academ.com
COMMENT=	DNS checker from the folks that run the .SE top level domain

BUILD_DEPENDS=	p5-Crypt-OpenSSL-Random>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-Random \
		p5-Digest-BubbleBabble>=0:${PORTSDIR}/security/p5-Digest-BubbleBabble \
		p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-IO-Socket-INET6>=2.51:${PORTSDIR}/net/p5-IO-Socket-INET6 \
		p5-Net-DNS>=0.65:${PORTSDIR}/dns/p5-Net-DNS \
		p5-Net-DNS-SEC>=0.15:${PORTSDIR}/dns/p5-Net-DNS-SEC \
		p5-Socket6>=0.19:${PORTSDIR}/net/p5-Socket6 \
		p5-Sys-Syslog>=0:${PORTSDIR}/sysutils/p5-Sys-Syslog \
		p5-Time-HiRes>=0:${PORTSDIR}/devel/p5-Time-HiRes \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Text-Template>=0:${PORTSDIR}/textproc/p5-Text-Template \
		p5-Mail-RFC822-Address>=0:${PORTSDIR}/mail/p5-Mail-RFC822-Address \
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite

USES=		perl5
USE_PERL5=	configure
CONFIGURE_SCRIPT+=	Makefile.PL INSTALLSITESCRIPT=${PREFIX}/libexec/dnscheck

WRKSRC=		${WRKDIR}/engine

DOCSDIR=	${PREFIX}/share/doc/DNSCheck
DOCS=		data-flow-batch.png DNSCheck.graffle data-flow-web.png call-flow.png database-schema.pdf
DOCSDB=		indexes.sql schema.sql drop.sql
PORTDOCS=	${DOCS} db
SUB_FILES=	pkg-install pkg-deinstall pkg-message

OPTIONS_DEFINE=		MYSQL DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
BUILD_DEPENDS+=	p5-DBI>=0:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS+=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
USE_MYSQL=	yes
.endif

MAN1=	dnscheck-zonediff.1 \
	dnscheck-dispatcher.1 \
	dnscheck-preflight.1 \
	dnscheck-hostsyntax.1 \
	dnscheck.1 \
	dnscheck-12hourmailer.1

MAN3=	DNSCheck::Test::Nameserver.3 \
	DNSCheck::Config.3 \
	DNSCheck.3 \
	DNSCheck::Lookup::DNS.3 \
	DNSCheck::Test::Consistency.3 \
	DNSCheck::Test::Host.3 \
	DNSCheck::Test::Connectivity.3 \
	DNSCheck::Overview.3 \
	DNSCheck::Test::Address.3 \
	DNSCheck::Test::DNSSEC.3 \
	DNSCheck::Test::SMTP.3 \
	DNSCheck::Lookup::ASN.3 \
	DNSCheck::Test::Zone.3 \
	DNSCheck::Logger.3 \
	DNSCheck::Test::Common.3 \
	DNSCheck::Test::Delegation.3 \
	DNSCheck::Test::SOA.3 \
	DNSCheck::Lookup::Resolver.3 \
	DNSCheck::Test::Mail.3

MANCOMPRESSED=	no

post-patch:
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC} |${XARGS} ${REINPLACE_CMD} \
		-e 's,%%PREFIX%%,${PREFIX},g'
.if ${PORT_OPTIONS:MMYSQL}
	@@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#" ${WRKSRC}/contrib/dnscheck-dispatcher.sh
.endif

pre-install:
	-@${FIND} ${WRKSRC} -name \*.orig -delete

post-install:
.if ${PORT_OPTIONS:MMYSQL}
# install startup script (if WITH_MYSQL is defined)
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/dnscheck-dispatcher.sh \
		${PREFIX}/etc/rc.d/dnscheck-dispatcher
	@${LN} -s ${PREFIX}/libexec/dnscheck/dnscheck-dispatcher ${PREFIX}/bin/dnscheck-dispatcher
	@${ECHO} bin/dnscheck-dispatcher >> ${TMPPLIST}
.endif
	@PKG_PREFIX=${PREFIX} BATCH=${BATCH} SU_CMD="${SU_CMD}" ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/db
	@${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	@${INSTALL_DATA} '${WRKSRC}/doc/DNSCheck Lib Descriptions.pdf' ${DOCSDIR}
	@${INSTALL_DATA} ${DOCSDB:S|^|${WRKSRC}/db/|} ${DOCSDIR}/db

.endif
	@${SED} -e 's#PREFIX#${PREFIX}#' ${PKGMESSAGE}

.include <bsd.port.mk>

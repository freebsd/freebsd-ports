# Created by: dnscheckengine-port@academ.com (Stan Barber)
# $FreeBSD$

PORTNAME=	dnscheckengine
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	dns perl5
MASTER_SITES=	ftp://www.ns.gen.tx.us/pub/software/dnscheck-se/
DISTNAME=	DNSCheck-1.1

MAINTAINER=	portmaster@bsdforge.com
COMMENT=	DNS checker from the folks that run the .SE top level domain

LICENSE=	BSD2CLAUSE

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
		p5-MIME-Lite>=0:${PORTSDIR}/mail/p5-MIME-Lite \
		p5-Net-IP>=0:${PORTSDIR}/net-mgmt/p5-Net-IP \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

USES=		perl5
USE_PERL5=	configure
USE_MYSQL=	yes
CONFIGURE_SCRIPT+=	Makefile.PL INSTALLSITESCRIPT=${PREFIX}/libexec/dnscheck

WRKSRC=		${WRKDIR}/engine

DOCSDIR=	${PREFIX}/share/doc/DNSCheck
DOCS=		data-flow-batch.png DNSCheck.graffle data-flow-web.png \
		call-flow.png database-schema.pdf
DOCSDB=		indexes.sql schema.sql drop.sql
PORTDOCS=	*
SUB_FILES=	pkg-message

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${FIND} ${WRKSRC} -name \*.orig -delete
	@${GREP} -Rl '%%[[:alpha:]]\+%%' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g'
	@${REINPLACE_CMD} -e "s#%%PREFIX%%#${PREFIX}#" \
		${WRKSRC}/contrib/dnscheck-dispatcher.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/dnscheck-dispatcher.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/dnscheck-dispatcher
	(cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} -s ../libexec/dnscheck/dnscheck-dispatcher . && \
		${LN} -s ../libexec/dnscheck/dnscheck dnscheckengine)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR} ${STAGEDIR}${DOCSDIR}/db
	${INSTALL_DATA} ${DOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} '${WRKSRC}/doc/DNSCheck Lib Descriptions.pdf' \
		${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${DOCSDB:S|^|${WRKSRC}/db/|} ${STAGEDIR}${DOCSDIR}/db
.endif

.include <bsd.port.mk>

# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	zonecheck
PORTVERSION=	3.0.5
PORTEPOCH=	1
CATEGORIES=	dns ipv6 ruby
MASTER_SITES=	http://www.zonecheck.fr/download/ \
		ftp://ftp.nic.fr/pub/mirror/zonecheck/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Perform consistency checks on DNS zones

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	rubygem-dnsruby>=1.47:${PORTSDIR}/dns/rubygem-dnsruby

USES=	gmake
USE_RUBY=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		BUGS CREDITS HISTORY INSTALL README TODO

OPTIONS_DEFINE=		CGI
OPTIONS_DEFAULT=
OPTIONS_SUB=

CGI_DESC=	Install with CGI support

.include <bsd.port.options.mk>

ZONECHECK_TARGET=	common cli

.if ${PORT_OPTIONS:MCGI}
ZONECHECK_TARGET+=	cgi
.endif

do-install:
	cd ${INSTALL_WRKSRC} && \
		${SETENV} LANG=en_US.UTF-8 ${RUBY} ./installer.rb ${ZONECHECK_TARGET} \
		-DETCDIST='-dist' -DRUBY="${RUBY}" -DPREFIX="${PREFIX}" \
		-DWWWDIR="${PREFIX}/www/${PORTNAME}" -DCHROOT="${STAGEDIR}"

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

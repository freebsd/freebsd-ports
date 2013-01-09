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

USE_GMAKE=	yes
USE_RUBY=	yes

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		zonecheck.1
DOCS=		BUGS INSTALL README TODO

OPTIONS_DEFINE=		CGI
OPTIONS_DEFAULT=	

CGI_DESC=	Install with CGI support

.include <bsd.port.options.mk>

ZONECHECK_TARGET=	common cli

.if ${PORT_OPTIONS:MCGI}
ZONECHECK_TARGET+=	cgi
PLIST_SUB+=	ZONECHECK_CGI=""
.else
PLIST_SUB+=	ZONECHECK_CGI="@comment "
.endif

do-install:
	@cd ${INSTALL_WRKSRC} && \
		${RUBY} ./installer.rb ${ZONECHECK_TARGET} \
		-DETCDIST='-dist' -DRUBY="${RUBY}" -DPREFIX="${PREFIX}" \
		-DWWWDIR="${PREFIX}/www/${PORTNAME}"

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>

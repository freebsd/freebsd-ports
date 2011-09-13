# New ports collection makefile for:	zonecheck
# Date created:		10 July 2003
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	zonecheck
PORTVERSION=	3.0.5
PORTEPOCH=	1
CATEGORIES=	dns ipv6 ruby
MASTER_SITES=	http://www.zonecheck.fr/download/ \
		ftp://ftp.nic.fr/pub/mirror/zonecheck/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
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

OPTIONS=	ZONECHECK_CGI	"Install with CGI support" off

.include <bsd.port.pre.mk>

ZONECHECK_TARGET=	common cli

.if defined(WITH_ZONECHECK_CGI)
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

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

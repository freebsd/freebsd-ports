# Created by: Janos.Mohacsi@bsd.hu
# $FreeBSD$

PORTNAME=	zonecheck
PORTVERSION=	3.0.5
PORTEPOCH=	1
CATEGORIES=	dns ruby
MASTER_SITES=	http://www.zonecheck.fr/download/ \
		ftp://ftp.nic.fr/pub/mirror/zonecheck/src/

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Perform consistency checks on DNS zones

BROKEN=		unfetchable

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/GPL

RUN_DEPENDS=	rubygem-dnsruby>=1.47:dns/rubygem-dnsruby

USES=		gmake tar:tgz
USE_RUBY=	yes

NO_ARCH=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

DOCS=		BUGS CREDITS HISTORY INSTALL README TODO

OPTIONS_DEFINE=		CGI DOCS
OPTIONS_DEFAULT=
OPTIONS_SUB=

CGI_DESC=	Install with CGI support

ZONECHECK_TARGET=	common cli

CGI_VARS=	ZONECHECK_TARGET+=cgi

do-install:
	cd ${INSTALL_WRKSRC} && \
		${SETENV} LANG=en_US.UTF-8 LC_ALL=en_US.UTF-8 ${RUBY} ./installer.rb ${ZONECHECK_TARGET} \
		-DETCDIST='-dist' -DRUBY="${RUBY}" -DPREFIX="${PREFIX}" \
		-DWWWDIR="${PREFIX}/www/${PORTNAME}" -DCHROOT="${STAGEDIR}"

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

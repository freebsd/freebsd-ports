# New ports collection makefile for:	zonecheck
# Date created:		10 July 2003
# Whom:	      		Janos.Mohacsi@bsd.hu
#
# $FreeBSD$
#

PORTNAME=	zonecheck
PORTVERSION=	2.1.1
PORTEPOCH=	1
CATEGORIES=	dns ipv6 ruby
MASTER_SITES=	ftp://ftp.nic.fr/pub/mirror/zonecheck/src/ \
		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	${PORTNAME}/src
EXTRACT_SUFX=	.tgz

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perform consistency checks on DNS zones

.if defined(WITH_X11)
RUN_DEPENDS=	${RUBY_SITEARCHLIBDIR}/gtk2.so:${PORTSDIR}/x11-toolkits/ruby-gtk2
.endif

USE_GMAKE=	yes
USE_RUBY=	yes
RUBY_VER=	1.8
USE_RUBY_FEATURES=	ruby18

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

MAN1=		zonecheck.1
DOCS=		BUGS INSTALL README TODO

ZONECHECK_TARGET=	common cli

.if defined(WITH_ZONECHECK_CGI)
ZONECHECK_TARGET+=	cgi
PLIST_SUB+=	ZONECHECK_CGI=""
.else
PLIST_SUB+=	ZONECHECK_CGI="@comment "

pre-everything::
	@${ECHO_MSG} "Use WITH_ZONECHECK_CGI=yes to install with CGI support"
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

.include <bsd.port.mk>

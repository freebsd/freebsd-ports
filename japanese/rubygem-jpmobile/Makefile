# New ports collection makefile for:	rubygem-jpmobile
# Date created:		2008-02-06
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	jpmobile
PORTVERSION=	0.1.6
CATEGORIES=	japanese www rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	A Rails plugin for Japanese mobile-phones

RUN_DEPENDS=	rubygem-rails>=3.0.3:${PORTSDIR}/www/rubygem-rails

LICENSE=	MIT

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

OPTIONS=	IPADDRESSES	"IP address validation support"	On \
		TERMINFO	"terminal information support"	On

.include <bsd.port.options.mk>

.if defined(WITH_IPADDRESSES)
RUN_DEPENDS+=	ja-jpmobile-ipaddresses>=0.0.1:${PORTSDIR}/japanese/rubygem-jpmobile-ipaddresses
.endif

.if defined(WITH_TERMINFO)
RUN_DEPENDS+=	ja-jpmobile-terminfo>=0.0.2:${PORTSDIR}/japanese/rubygem-jpmobile-terminfo
.endif

.include <bsd.port.mk>

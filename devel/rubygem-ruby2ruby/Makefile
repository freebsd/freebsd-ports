# New ports collection makefile for:	rubygem-ruby2ruby
# Date created:		2007-09-28
# Whom:			TAKATSU Tomonari <tota@rtfm.jp>
#
# $FreeBSD$
#

PORTNAME=	ruby2ruby
PORTVERSION=	1.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	seattlerb

MAINTAINER=	tota@rtfm.jp
COMMENT=	A pure ruby code generator easily from ParseTree's Sexps # '

BUILD_DEPENDS=	rubygem-parsetree>=3.0:${PORTSDIR}/devel/rubygem-parsetree \
		rubygem-hoe>=1.8.2:${PORTSDIR}/devel/rubygem-hoe
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/r2r_show

.include <bsd.port.mk>

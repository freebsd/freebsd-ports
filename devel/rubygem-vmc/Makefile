# New ports collection makefile for:	rubygem-vmc
# Date created:		2010 12-15
# Whom:			Hsin-Han You <hhyou@cs.nctu.edu.tw>
#
# $FreeBSD$

PORTNAME=	vmc
PORTVERSION=	0.3.12
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	hhyou@cs.nctu.edu.tw
COMMENT=	The command line client for Cloud Foundry

RUN_DEPENDS=	rubygem-terminal-table>=1.4.2:${PORTSDIR}/textproc/rubygem-terminal-table \
		rubygem-rest-client>=1.6.1<1.7.0:${PORTSDIR}/www/rubygem-rest-client \
		rubygem-highline>=1.6.1:${PORTSDIR}/devel/rubygem-highline \
		rubygem-rubyzip2>=2.0.1:${PORTSDIR}/archivers/rubygem-rubyzip2 \
		rubygem-json_pure>=1.5.1:${PORTSDIR}/devel/rubygem-json_pure

LICENSE=	MIT

BROKEN=		Needs older rubygem-json

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/vmc

.include <bsd.port.mk>

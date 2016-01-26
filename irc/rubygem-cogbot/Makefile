# $FreeBSD$

PORTNAME=	cogbot
PORTVERSION=	0.1.4
PORTREVISION=	1
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	Irc bot based on Cinch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cinch>=2.3.1:${PORTSDIR}/irc/rubygem-cinch \
		rubygem-thor>=0.19.1:${PORTSDIR}/devel/rubygem-thor \
		rubygem-eventmachine>=1.0.8:${PORTSDIR}/devel/rubygem-eventmachine \
		rubygem-eventmachine_httpserver>=0.2.1:${PORTSDIR}/www/rubygem-eventmachine_httpserver \
		rubygem-nokogiri>=1.6.6.4:${PORTSDIR}/textproc/rubygem-nokogiri \
		rubygem-daemons>=1.2.3:${PORTSDIR}/devel/rubygem-daemons \
		rubygem-twitter>=1.6.6.2:${PORTSDIR}/net/rubygem-twitter \
		rubygem-json>=1.8.3:${PORTSDIR}/devel/rubygem-json \
		rubygem-yajl-ruby>=1.2.1:${PORTSDIR}/devel/rubygem-yajl-ruby \
		rubygem-fortune_gem>=0.0.8:${PORTSDIR}/games/rubygem-fortune_gem

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/cogbot

.include <bsd.port.mk>

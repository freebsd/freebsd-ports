# $FreeBSD$

PORTNAME=	cogbot
PORTVERSION=	0.1.13
PORTREVISION=	5
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	Irc bot based on Cinch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cinch>=2.3.3:irc/rubygem-cinch \
		rubygem-thor>=0.19.4:devel/rubygem-thor \
		rubygem-eventmachine>=1.2.3:devel/rubygem-eventmachine \
		rubygem-eventmachine_httpserver>=0.2.1:www/rubygem-eventmachine_httpserver \
		rubygem-nokogiri>=1.8.0:textproc/rubygem-nokogiri \
		rubygem-daemons>=1.2.4:devel/rubygem-daemons \
		rubygem-twitter>=6.1.0:net/rubygem-twitter \
		rubygem-json>=2.1.0:devel/rubygem-json \
		rubygem-yajl-ruby>=1.3.0:devel/rubygem-yajl-ruby \
		rubygem-fortune_gem>=0.0.9:games/rubygem-fortune_gem

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/cogbot

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	cogbot
PORTVERSION=	0.1.7
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	mose@mose.com
COMMENT=	Irc bot based on Cinch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-cinch>=2.3.1:irc/rubygem-cinch \
		rubygem-thor>=0.19.1:devel/rubygem-thor \
		rubygem-eventmachine>=1.0.9:devel/rubygem-eventmachine \
		rubygem-eventmachine_httpserver>=0.2.1:www/rubygem-eventmachine_httpserver \
		rubygem-nokogiri>=1.6.6.4:textproc/rubygem-nokogiri \
		rubygem-daemons>=1.2.3:devel/rubygem-daemons \
		rubygem-twitter>=5.15.0:net/rubygem-twitter \
		rubygem-json>=1.8.3:devel/rubygem-json \
		rubygem-yajl-ruby>=1.2.1:devel/rubygem-yajl-ruby \
		rubygem-fortune_gem>=0.0.8:games/rubygem-fortune_gem

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/cogbot

.include <bsd.port.mk>

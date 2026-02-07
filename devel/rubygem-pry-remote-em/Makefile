PORTNAME=	pry-remote-em
PORTVERSION=	1.1.2
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Connect to Pry remotely using EventMachine
WWW=		https://github.com/gruis/pry-remote-em

LICENSE=	MIT

RUN_DEPENDS=	rubygem-eventmachine>=1<2:devel/rubygem-eventmachine \
		rubygem-highline2>=2.0<3:devel/rubygem-highline2 \
		rubygem-msgpack>=1<2:devel/rubygem-msgpack \
		rubygem-pry>=0.11<1:devel/rubygem-pry \
		rubygem-ruby-termios>=1.0<2:comms/rubygem-ruby-termios

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/pry-remote-em \
		bin/pry-remote-em-broker

.include <bsd.port.mk>

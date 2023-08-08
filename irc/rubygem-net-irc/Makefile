PORTNAME=	net-irc
PORTVERSION=	0.0.9
PORTREVISION=	1
CATEGORIES=	irc rubygems
MASTER_SITES=	RG

MAINTAINER=	tota@FreeBSD.org
COMMENT=	Ruby library for implementing IRC server and client
WWW=		https://github.com/cho45/net-irc

LICENSE=	RUBY

NO_ARCH=	yes

REINPLACE_ARGS=	-i ''
USES=		gem

post-patch:
	@${REINPLACE_CMD} -e '1d' \
		${WRKSRC}/spec/channel_manager_spec.rb \
		${WRKSRC}/spec/net-irc_spec.rb

.include <bsd.port.mk>

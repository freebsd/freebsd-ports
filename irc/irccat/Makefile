PORTNAME=	irccat
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.13
CATEGORIES=	irc

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Send events to IRC channels from scripts and other applications
WWW=		https://github.com/irccloud/irccat

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_RC_SUBR=	irccat

GO_MODULE=	github.com/irccloud/irccat

SUB_FILES=	pkg-message

PLIST_FILES=	"@sample ${ETCDIR}/irccat.yaml.sample" \
		bin/${PORTNAME}

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/irccat.json \
		${STAGEDIR}${ETCDIR}/irccat.yaml.sample

.include <bsd.port.mk>

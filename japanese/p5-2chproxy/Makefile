# $FreeBSD$

PORTNAME=	2chproxy
PORTVERSION=	1.0.1
DISTVERSIONPREFIX=	v
CATEGORIES=	japanese perl5 www
PKGNAMEPREFIX=	ja-p5-

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Proxy server for 2ch.net

LICENSE=	MIT

RUN_DEPENDS=	p5-HTTP-Daemon>0:www/p5-HTTP-Daemon \
		p5-IO-Compress>0:archivers/p5-IO-Compress \
		p5-URI>0:net/p5-URI \
		p5-libwww>0:www/p5-libwww

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}.pl
USE_GITHUB=	yes
GH_ACCOUNT=	yama-natuki
GH_PROJECT=	${PORTNAME}.pl
USE_RC_SUBR=	twochproxy
NO_BUILD=	yes
PLIST_FILES=	sbin/${PORTNAME}.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/sbin

.include <bsd.port.mk>

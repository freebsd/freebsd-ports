PORTNAME=	lolcat
PORTVERSION=	100.0.1
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Rainbows and unicorns
WWW=		https://github.com/busyloop/lolcat

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-manpages>=0.6.1<1:devel/rubygem-manpages \
		rubygem-optimist>=3.0.0<4:devel/rubygem-optimist \
		rubygem-paint>=2.1<3:devel/rubygem-paint

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/lolcat \
		share/man/man6/lolcat.6.gz

CONFLICTS_INSTALL=	lolcat # bin/lolcat

post-install:
	${INSTALL_MAN} ${WRKSRC}/man/lolcat.6 ${STAGEDIR}${PREFIX}/share/man/man6/lolcat.6

.include <bsd.port.mk>

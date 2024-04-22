PORTNAME=	scrm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
PORTREVISION=	1
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coalescent simulator for biological sequences
WWW=		https://scrm.github.io/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake
USE_GITHUB=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

PLIST_FILES=	bin/scrm \
		share/man/man1/scrm.1.gz

.include <bsd.port.mk>

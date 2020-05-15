# $FreeBSD$

PORTNAME=	scrm
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.4
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Coalescent simulator for biological sequences

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf compiler:c++11-lang gmake
USE_GITHUB=	yes

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/scrm \
		man/man1/scrm.1.gz

.include <bsd.port.mk>

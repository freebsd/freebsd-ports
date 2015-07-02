# $FreeBSD$

PORTNAME=	lolcat
PORTVERSION=	42.0.99
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	RG

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Rainbows and unicorns

RUN_DEPENDS=	rubygem-trollop>=1.9:${PORTSDIR}/devel/rubygem-trollop \
		rubygem-paint>=0.8.5:${PORTSDIR}/devel/rubygem-paint

NO_ARCH=	yes

nUSE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

post-install:
	${ECHO_CMD} "bin/lolcat" >> ${TMPPLIST}

.include <bsd.port.mk>

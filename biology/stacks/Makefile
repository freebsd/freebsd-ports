# $FreeBSD$

PORTNAME=	stacks
DISTVERSION=	1.48
CATEGORIES=	biology
MASTER_SITES=	http://catchenlab.life.illinois.edu/stacks/source/

MAINTAINER=	jwb@FreeBSD.org
COMMENT=	Software pipeline for building loci from short-read sequences

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gmake python shebangfix
SHEBANG_FILES=	scripts/*.pl scripts/*.py
GNU_CONFIGURE=	yes

LDFLAGS+=	-lpthread

.include <bsd.port.mk>

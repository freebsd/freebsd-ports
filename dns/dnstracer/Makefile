# Created by: Edwin Groothuis <edwin@mavetju.org>
# $FreeBSD$

PORTNAME=	dnstracer
DISTVERSION=	1.10
CATEGORIES=	dns
MASTER_SITES=	http://www.mavetju.org/download/

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Trace a chain of DNS servers to the source

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		perl5 tar:bz2
USE_PERL5=	build

MAKE_ARGS=	VERSION="${PORTVERSION}"
WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	bin/dnstracer \
		share/man/man8/dnstracer.8.gz

.include <bsd.port.mk>

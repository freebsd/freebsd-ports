# Created by: ijliao
# $FreeBSD$

PORTNAME=	stlfilt
PORTVERSION=	20080203
CATEGORIES=	devel
MASTER_SITES=	https://www.bdsoft.com/dist/
DISTNAME=	g${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	STL Error Message Decryptor for C++

LICENSE=	MIT

USES=		perl5 tar
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/gSTLFilt.pl bin/gfilt

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/gSTLFilt.pl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/gfilt ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

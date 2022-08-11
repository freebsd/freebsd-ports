PORTNAME=	plutil
PORTVERSION=	1.7
CATEGORIES=	converters perl5
MASTER_SITES=	LOCAL/ehaupt
PKGNAMEPREFIX=	p5-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Perl implementation of Mac OS X plutil

USES=		shebangfix perl5 tar:xz
USE_PERL5=	run
NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	${PORTNAME}.pl

PLIST_FILES=	bin/plutil.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

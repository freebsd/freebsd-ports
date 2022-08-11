PORTNAME=	abcselect
PORTVERSION=	1.5
CATEGORIES=	audio
MASTER_SITES=	http://www.lautengesellschaft.de/cdmm/
DISTNAME=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract parts, movements, etc from abc music files

USES=		shebangfix perl5
USE_PERL5=	run
NO_BUILD=	yes

SHEBANG_FILES=	abcselect

PLIST_FILES=	bin/abcselect \
		man/man1/abcselect.1.gz

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/abcselect ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/abcselect.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>

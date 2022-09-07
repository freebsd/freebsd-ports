PORTNAME=	mencal
PORTVERSION=	3.0
CATEGORIES=	deskutils
MASTER_SITES=	http://kyberdigi.cz/projects/mencal/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple variation of the unix command cal
WWW=		https://kyberdigi.cz/projects/mencal/english.html

LICENSE=	GPLv2

NO_BUILD=	yes

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_PERL5=	run

PLIST_FILES=	bin/mencal

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>

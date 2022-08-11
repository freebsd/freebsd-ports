PORTNAME=	when
PORTVERSION=	1.1.42
CATEGORIES=	deskutils

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple personal calendar

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	run

MAKE_ARGS=	MANDIR=${PREFIX}/share/man/man1 prefix=${PREFIX}
NO_ARCH=	yes
NO_BUILD=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	bcrowell

SHEBANG_FILES=	when

.include <bsd.port.mk>

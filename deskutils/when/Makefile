PORTNAME=	when
PORTVERSION=	1.1.45
CATEGORIES=	deskutils
MASTER_SITES=	https://bitbucket.org/ben-crowell/when/get/${PORTVERSION}.tgz?dummy=/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple personal calendar
WWW=		https://www.lightandmatter.com/when/when.html \
		https://bitbucket.org/ben-crowell/when

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

USES=		perl5 shebangfix
USE_PERL5=	run

MAKE_ARGS=	prefix=${PREFIX}
NO_ARCH=	yes
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/ben-crowell-when-965b37762cc7/

PORTSCOUT=	skipv:1.2.00

SHEBANG_FILES=	when

.include <bsd.port.mk>

# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	IO-Pager
PORTVERSION=	1.01
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Select a pager, optionally pipe it output if destination is a TTY

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-File-Which>=0:sysutils/p5-File-Which \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

USES=		perl5 shebangfix tar:tgz
USE_PERL5=	configure

NO_ARCH=	yes

SHEBANG_FILES=	lib/IO/Pager/tp
perl_OLD_CMD=	"/bin/env perl"

.include <bsd.port.mk>

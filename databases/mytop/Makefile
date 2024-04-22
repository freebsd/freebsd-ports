PORTNAME=	mytop
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Top clone for MySQL
WWW=		https://jeremy.zawodny.com/mysql/mytop/

LICENSE=	GPLv2

RUN_DEPENDS=	${DBD_MYSQL} \
		p5-DBI>=1.13:databases/p5-DBI \
		p5-Term-ReadKey>=2.10:devel/p5-Term-ReadKey

USE_GITHUB=	yes
GH_ACCOUNT=	jzawodn
GH_TAGNAME=	437f2ef

NO_ARCH=	yes

USES+=		mysql perl5
USE_PERL5=	configure

PLIST_FILES=	bin/mytop \
		${SITE_MAN1}/mytop.1.gz

.include <bsd.port.mk>

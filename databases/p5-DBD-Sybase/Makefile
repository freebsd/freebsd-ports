# Created by: Sheldon Hearn <sheldonh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-Sybase
PORTVERSION=	1.16
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sybase DBI driver for Perl 5

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI
LIB_DEPENDS=	libct.so:databases/freetds

CONFIGURE_ENV=	SYBASE=${LOCALBASE}
USES=		gettext perl5
USE_PERL5=	configure

.if defined(BATCH)
CONFIGURE_ARGS=	< /dev/null
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/DBD/Sybase/Sybase.so

.include <bsd.port.mk>

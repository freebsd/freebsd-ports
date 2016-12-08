# Created by: Sheldon Hearn <sheldonh@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBD-Sybase
PORTVERSION=	1.15
PORTREVISION=	2
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Sybase DBI driver for Perl 5

BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI
LIB_DEPENDS=	libct.so:databases/freetds
RUN_DEPENDS=	p5-DBI>=0:databases/p5-DBI

CONFIGURE_ENV=	SYBASE=${LOCALBASE}
USES=		gettext perl5
USE_PERL5=	configure

.if defined(BATCH)
CONFIGURE_ARGS=	< /dev/null
.endif

.include <bsd.port.mk>

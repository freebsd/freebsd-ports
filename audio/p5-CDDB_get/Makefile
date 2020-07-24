# Created by: Oyvind Moll <oyvindmo@initio.no>
# $FreeBSD$

PORTNAME=	CDDB_get
PORTVERSION=	2.28
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FONKIE
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	High-level interface to the Compact Disc Database

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/Copying

USES=		perl5 shebangfix
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	skipv:2.28.1

SHEBANG_FILES=	cddb.pl

.include <bsd.port.mk>

# Created by: Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
# $FreeBSD$

PORTNAME=	MP3-Find
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search and sort MP3 files based on their ID3 tags

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-MP3-Info>=0:audio/p5-MP3-Info
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DB
DB_DESC=	Use database backend

DB_BUILD_DEPENDS=	p5-DBI>=0:databases/p5-DBI \
			p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
			p5-SQL-Abstract>=0:databases/p5-SQL-Abstract
DB_RUN_DEPENDS=		${DB_BUILD_DEPENDS}

.include <bsd.port.mk>

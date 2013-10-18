# Created by: Yen-Ming Lee <leeym@FreeBSD.org>
# $FreeBSD$

PORTNAME=	DBZ_File
PORTVERSION=	1.1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	leeym@FreeBSD.org
COMMENT=	Perl module to access a DBZ database

DEPRECATED=	BRoken for more than 6 month
EXPIRATION_DATE=	2013-11-18

USES=		perl5
USE_PERL5=	configure
CONFIGURE_ARGS=	DEFINE="-I${FILESDIR}" POLLUTE=1

WRKSRC=		${WRKDIR}/DBZ_File

MAN3=		DBZ_File.3

NO_STAGE=	yes
.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} > 501400
BROKEN=	POLLUTE=1 is gone, does not compile, has not been released since 1997
.endif
.include <bsd.port.post.mk>

# New ports collection makefile for:	devel/p5-File-ExtAttr
# Date created:				01 June 2007
# Whom:					Timur Bakeyev <bat@cpan.org>
#
# $FreeBSD$
#

PORTNAME=		File-ExtAttr
PORTVERSION=		1.07
CATEGORIES=		devel perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		timur@FreeBSD.org
COMMENT=		Access to extended attributes of the files

PERL_CONFIGURE=		5.8.0+

MAN3=			File::ExtAttr.3 File::ExtAttr::Tie.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500018
IGNORE=			extended attributes require FreeBSD 5.x at least after 20010326
.endif

.include <bsd.port.post.mk>

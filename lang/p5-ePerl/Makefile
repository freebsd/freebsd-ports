# New ports collection makefile for:	p5-ePerl
# Date created:		03-Sep-1997
# Whom:	      		Ralf S. Engelschall <rse@engelschall.com>
#
# $FreeBSD$
#

PORTNAME=	eperl
PORTVERSION=	2.2.14
CATEGORIES=	lang www perl5
MASTER_SITES=	ftp://ftp.ossp.org/pkg/tool/eperl/ \
		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=Parse
PKGNAMEPREFIX=	p5-

MAINTAINER=	rse@engelschall.com
COMMENT=	Perl Modules of ePerl package: Parse::ePerl, Apache::ePerl

PERL_CONFIGURE=	yes

MAN3=		Parse::ePerl.3 Apache::ePerl.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Configure fails"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	MySQL-Diff
# Date created:	   11 August 2003
# Whom:		   Andrew McNaughton <andrew@scoop.co.nz>
#
# $FreeBSD$
#

PORTNAME=       MySQL-Diff
PORTVERSION=	0.33
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	MySQL
PKGNAMEPREFIX=	p5-

MAINTAINER=	andrew@scoop.co.nz
COMMENT=	Perl module for comparing the table structure of two MySQL databases

BUILD_DEPENDS=	${SITE_PERL}/Class/MakeMethods/Template.pm:${PORTSDIR}/devel/p5-Class-MakeMethods \
		${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

post-install:
	$(INSTALL_SCRIPT) $(WRKSRC)/mysqldiff $(PREFIX)/bin

.include <bsd.port.mk>

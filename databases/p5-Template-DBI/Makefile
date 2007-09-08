# New ports collection makefile for:	databases/p5-Template-DBI
# Date created:				04 December 2006
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Template-DBI
PORTVERSION=	2.64
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Template
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Template::Plugin::DBI - Template interface to the DBI module

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Template::DBI.3 \
	Template::Plugin::DBI.3

post-patch:
	${PERL} -i -pe 's|TT_QUIET\s*=\s*0|TT_QUIET = 1|' ${WRKSRC}/Makefile.PL
	${PERL} -i -pe 's|TT_ACCEPT\s*=\s*0|TT_ACCEPT = 1|' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

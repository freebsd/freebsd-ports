# New ports collection makefile for:	databases/p5-DBIx-MySQLSequence
# Date created:				18 March 2006
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBIx-MySQLSequence
PORTVERSION=	1.00
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	DBIx
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Proper and correct (emulated) sequence support for MySQL

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/DBD/mysql.pm:${PORTSDIR}/databases/p5-DBD-mysql \
		${SITE_PERL}/${PERL_ARCH}/DBI.pm:${PORTSDIR}/databases/p5-DBI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	DBIx::MySQLSequence.3

post-patch:
	@${RM} ${WRKSRC}/inc/Module/Install/AutoInstall.pm
	@${PERL} -pi -e '$$_="" if m|Install/AutoInstall|' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e '$$_="" if m/Test::More|auto_install/' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

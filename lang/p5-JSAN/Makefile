# New ports collection makefile for:    p5-JSAN
# Date created:		2006/12/23
# Whom:	      		chinsan
#
# $FreeBSD$
#

PORTNAME=	JSAN
PORTVERSION=	0.07
PORTREVISION=	4
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CW/CWEST
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	JavaScript Archive Network (JSAN) Shell

BUILD_DEPENDS=	p5-Class-DBI-SQLite>=0:${PORTSDIR}/databases/p5-Class-DBI-SQLite \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Class-DBI-DATA-Schema>=0:${PORTSDIR}/databases/p5-Class-DBI-DATA-Schema \
		p5-Class-DBI-Loader>=0:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		p5-File-Temp>=0:${PORTSDIR}/devel/p5-File-Temp \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-Test-Differences>=0:${PORTSDIR}/devel/p5-Test-Differences \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath \
		p5-ExtUtils-AutoInstall>=0:${PORTSDIR}/devel/p5-ExtUtils-AutoInstall
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	JSAN::Shell.3 JSAN.3 JSAN::Indexer::Creator.3 JSAN::Indexer.3

post-patch:
	@${REINPLACE_CMD} -e "40 s,new,new(\'jsan\')," ${WRKSRC}/lib/JSAN.pm
	${FIND} ${WRKSRC}/lib -name "*.bak" -delete

.include <bsd.port.mk>

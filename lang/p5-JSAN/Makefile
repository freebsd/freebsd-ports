# Created by: chinsan
# $FreeBSD$

PORTNAME=	JSAN
PORTVERSION=	0.07
PORTREVISION=	7
CATEGORIES=	lang perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:CWEST
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	JavaScript Archive Network (JSAN) Shell

BUILD_DEPENDS=	p5-Class-DBI-SQLite>=0:${PORTSDIR}/databases/p5-Class-DBI-SQLite \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Class-Accessor>=0:${PORTSDIR}/devel/p5-Class-Accessor \
		p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Class-DBI-DATA-Schema>=0:${PORTSDIR}/databases/p5-Class-DBI-DATA-Schema \
		p5-Class-DBI-Loader>=0:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		p5-SQL-Translator>=0:${PORTSDIR}/databases/p5-SQL-Translator \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-XML-XPath>=0:${PORTSDIR}/textproc/p5-XML-XPath
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e "40 s,new,new(\'jsan\')," ${WRKSRC}/lib/JSAN.pm
	${FIND} ${WRKSRC}/lib -name "*.bak" -delete

.include <bsd.port.mk>

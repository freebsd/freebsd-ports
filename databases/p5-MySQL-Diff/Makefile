# Created by: Andrew McNaughton <andrew@scoop.co.nz>
# $FreeBSD$

PORTNAME=	MySQL-Diff
PORTVERSION=	0.43
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	Perl module for comparing the table structure of two MySQL databases

BUILD_DEPENDS=	p5-Class-MakeMethods>=0:${PORTSDIR}/devel/p5-Class-MakeMethods \
		p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		mysqldiff.1
MAN3=		MySQL::Diff.3 \
		MySQL::Diff::Database.3 \
		MySQL::Diff::Table.3 \
		MySQL::Diff::Utils.3

post-patch:
	@${REINPLACE_CMD} -e '1 s|/usr/bin/perl|${PERL}|' ${WRKSRC}/bin/mysqldiff

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/mysqldiff ${PREFIX}/bin/

.include <bsd.port.mk>

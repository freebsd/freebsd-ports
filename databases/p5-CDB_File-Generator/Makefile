PORTNAME=	CDB_File-Generator
PORTVERSION=	0.030
PORTREVISION=	1
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate massive sorted CDB files simply

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	cdbmake:databases/cdb \
		p5-CDB_File>=0:databases/p5-CDB_File

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

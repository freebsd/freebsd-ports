# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	CDB_File-Generator
PORTVERSION=	0.030
CATEGORIES=	databases perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generate massive sorted CDB files simply

BUILD_DEPENDS=	${LOCALBASE}/bin/cdbmake:${PORTSDIR}/databases/cdb \
		p5-CDB_File>=0:${PORTSDIR}/databases/p5-CDB_File
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

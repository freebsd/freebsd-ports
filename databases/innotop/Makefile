# Created by: Steven Kreuzer <skreuzer@f2o.org>
# $FreeBSD$

PORTNAME=	innotop
PORTVERSION=	1.11.4
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	MySQL and InnoDB monitoring program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBI>=1.46:databases/p5-DBI \
		p5-Term-ReadKey>=2.10:devel/p5-Term-ReadKey
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_GITHUB=	yes

USES=		mysql perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/innotop|${PREFIX}/etc|g' ${WRKSRC}/innotop

.include <bsd.port.mk>

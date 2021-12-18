# Created by: Steven Kreuzer <skreuzer@FreeBSD.org>

PORTNAME=	innotop
PORTVERSION=	1.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	databases

MAINTAINER=	skreuzer@FreeBSD.org
COMMENT=	MySQL and InnoDB monitoring program

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-DBD-mysql>=0:databases/p5-DBD-mysql \
		p5-DBI>=1.46:databases/p5-DBI \
		p5-Term-ReadKey>=2.10:devel/p5-Term-ReadKey \
		p5-Time-HiRes>0:devel/p5-Time-HiRes \
		p5-Term-ANSIColor>0:devel/p5-Term-ANSIColor \
		p5-Term-ReadLine>0:devel/p5-Term-ReadLine
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		mysql perl5

USE_PERL5=	configure
USE_GITHUB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/etc/innotop|${PREFIX}/etc|g' ${WRKSRC}/innotop

.include <bsd.port.mk>

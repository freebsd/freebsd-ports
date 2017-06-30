# Created by: ijliao
# $FreeBSD$

PORTNAME=	mtop
PORTVERSION=	0.6.6
PORTREVISION=	5
CATEGORIES=	databases
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	MySQL Monitoring Tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-Curses>=0:devel/p5-Curses \
		p5-DBD-mysql>=0:databases/p5-DBD-mysql
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	${RM} ${WRKSRC}/cpan2spec.pl

.include <bsd.port.mk>

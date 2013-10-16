# Created by: Sergey Skvortsov <skv@protey.ru>
# $FreeBSD$

PORTNAME=	POE-Component-RRDTool
PORTVERSION=	0.18
PORTREVISION=	4
CATEGORIES=	databases perl5 devel
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	POE interface to Round Robin Database Tools

BUILD_DEPENDS=	p5-POE>=0:${PORTSDIR}/devel/p5-POE \
		${LOCALBASE}/bin/rrdtool:${PORTSDIR}/databases/rrdtool
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure patch
CONFIGURE_ARGS=	</dev/null

post-patch:
	@${PERL} -pi -e 's/(\(\$$maj, \$$min, \$$sub\))/$$1; $$1/' \
		${WRKSRC}/Makefile.PL

.include <bsd.port.mk>

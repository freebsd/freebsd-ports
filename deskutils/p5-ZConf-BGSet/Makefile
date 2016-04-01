# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-BGSet
PORTVERSION=	1.0.0
PORTREVISION=	6
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Background management utility and Perl module that uses ZConf

BUILD_DEPENDS=	p5-Image-Size-FillFullSelect>=0.1.0:graphics/p5-Image-Size-FillFullSelect \
		p5-ZConf>=:net/p5-ZConf \
		${LOCALBASE}/bin/hsetroot:graphics/hsetroot \
		p5-Imager-AverageGray>=0.0.0:graphics/p5-Imager-AverageGray \
		p5-X11-Resolution>=0.0.0:x11/p5-X11-Resolution \
		p5-String-ShellQuote>=1.04:textproc/p5-String-ShellQuote
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/zbgset-admin bin/zbgset bin/zbgset-pt
USE_PERL5=	configure

.include <bsd.port.mk>

PORTNAME=	IPC-ShellCmd
PORTVERSION=	0.005
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ANDREWF
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Run a command with a given environment and capture output
WWW=		https://metacpan.org/release/IPC-ShellCmd

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote

USES=		perl5 sudo
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

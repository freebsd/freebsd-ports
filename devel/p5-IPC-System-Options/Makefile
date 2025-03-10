PORTNAME=	IPC-System-Options
PORTVERSION=	0.341
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl system(), readpipe()/qx, IPC::Run's run(), start() (with more options)
WWW=		https://metacpan.org/dist/IPC-System-Options

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Capture-Tiny>=0:devel/p5-Capture-Tiny \
		p5-IPC-Run>=0:devel/p5-IPC-Run \
		p5-Log-ger>=0.018:devel/p5-Log-ger \
		p5-Proc-ChildError>=0:devel/p5-Proc-ChildError \
		p5-String-ShellQuote>=0:textproc/p5-String-ShellQuote
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>

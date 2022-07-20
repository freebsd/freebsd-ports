PORTNAME=	Data-Unixish
PORTVERSION=	1.572
PORTREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Implementation for Unixish, a data transformation framework

BUILD_DEPENDS=	p5-Exporter>=5.57:devel/p5-Exporter \
		p5-File-Which>0:sysutils/p5-File-Which \
		p5-IPC-Cmd>0.52:devel/p5-IPC-Cmd \
		p5-JSON-MaybeXS>0:converters/p5-JSON-MaybeXS \
		p5-Log-ger>0.027:devel/p5-Log-ger \
		p5-Module-Load>0:devel/p5-Module-Load \
		p5-Number-Format-Metric>0:textproc/p5-Number-Format-Metric \
		p5-Number-Format>0:textproc/p5-Number-Format \
		p5-Package-Util-Lite>=0.001:devel/p5-Package-Util-Lite \
		p5-Sort-Sub>0.111:devel/p5-Sort-Sub \
		p5-String-Pad>0:textproc/p5-String-Pad \
		p5-String-ShellQuote>0:textproc/p5-String-ShellQuote \
		p5-Text-ANSI-Util>=0.22:textproc/p5-Text-ANSI-Util \
		p5-Text-ANSI-WideUtil>0:textproc/p5-Text-ANSI-WideUtil \
		p5-Text-sprintfn>0:textproc/p5-Text-sprintfn \
		p5-Tie-File>0:devel/p5-Tie-File \
		p5-Tie-Simple>0:devel/p5-Tie-Simple
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 pkgconfig
USE_PERL5=	configure

.include <bsd.port.mk>

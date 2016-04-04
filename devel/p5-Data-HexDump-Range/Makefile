# Created by: gebhart@secnetix.de
# $FreeBSD$

PORTNAME=	Data-HexDump-Range
PORTVERSION=	0.13.59
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	gebhart@secnetix.de
COMMENT=	Hexadecimal Range Dumper with color, bitfields and skip ranges

BUILD_DEPENDS=	p5-Readonly>=0:devel/p5-Readonly \
		p5-Data-TreeDumper>=0:devel/p5-Data-TreeDumper \
		p5-List-MoreUtils>=0:lang/p5-List-MoreUtils \
		p5-Sub-Exporter>=0:devel/p5-Sub-Exporter \
		p5-Text-Diff>=0:textproc/p5-Text-Diff \
		p5-Text-Colorizer>=0:textproc/p5-Text-Colorizer \
		p5-Term-Bash-Completion-Generator>=0:shells/p5-Term-Bash-Completion-Generator
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	modbuild

.include <bsd.port.mk>

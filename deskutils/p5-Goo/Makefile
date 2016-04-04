# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Goo
PORTVERSION=	0.09
PORTREVISION=	3
CATEGORIES=	deskutils sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Stick Things together with The Goo

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Config-Auto>=0:devel/p5-Config-Auto \
		p5-Config-Tiny>=0:devel/p5-Config-Tiny \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-Devel-Symdump>=0:devel/p5-Devel-Symdump \
		p5-File-Grep>=0:devel/p5-File-Grep \
		p5-File-NCopy>=0:devel/p5-File-NCopy \
		p5-libwww>=0:www/p5-libwww \
		perltidy:devel/p5-Perl-Tidy \
		p5-Term-ProgressBar>=0:devel/p5-Term-ProgressBar \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey \
		p5-Text-FormatTable>=0:textproc/p5-Text-FormatTable
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	lib/Goo/Thing/*/*.pl
USE_PERL5=	configure
NO_ARCH=	yes

.include <bsd.port.mk>

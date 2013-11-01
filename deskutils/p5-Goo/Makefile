# Created by: Aaron Dalton <aaron@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Goo
PORTVERSION=	0.09
PORTREVISION=	1
CATEGORIES=	deskutils sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Stick Things together with The Goo

BUILD_DEPENDS=	p5-Config-Auto>=0:${PORTSDIR}/devel/p5-Config-Auto \
		p5-Config-Tiny>=0:${PORTSDIR}/devel/p5-Config-Tiny \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-Devel-Symdump>=0:${PORTSDIR}/devel/p5-Devel-Symdump \
		p5-File-Grep>=0:${PORTSDIR}/devel/p5-File-Grep \
		p5-File-NCopy>=0:${PORTSDIR}/devel/p5-File-NCopy \
		p5-libwww>=0:${PORTSDIR}/www/p5-libwww \
		perltidy>=0:${PORTSDIR}/devel/perltidy \
		p5-Term-ProgressBar>=0:${PORTSDIR}/devel/p5-Term-ProgressBar \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-Text-FormatTable>=0:${PORTSDIR}/textproc/p5-Text-FormatTable
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

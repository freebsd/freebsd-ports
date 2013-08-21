# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Data-Printer
PORTVERSION=	0.30
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/0$//}

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Colored pretty-print of Perl data structures and objects

BUILD_DEPENDS=	p5-Clone>=0:${PORTSDIR}/devel/p5-Clone \
		p5-File-HomeDir>=0.91:${PORTSDIR}/devel/p5-File-HomeDir \
		p5-Hash-FieldHash>=0:${PORTSDIR}/devel/p5-Hash-FieldHash \
		p5-Moose>=2:${PORTSDIR}/devel/p5-Moose \
		p5-Sort-Naturally>=0:${PORTSDIR}/textproc/p5-Sort-Naturally
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Capture-Tiny>=0:${PORTSDIR}/devel/p5-Capture-Tiny \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-IO-Pty-Easy>=0:${PORTSDIR}/devel/p5-IO-Pty-Easy \
		p5-Test-Pod>=1.41:${PORTSDIR}/devel/p5-Test-Pod

USE_PERL5=	configure
USES=		perl5

MAN3=		Data::Printer.3 \
		Data::Printer::Filter.3 \
		Data::Printer::Filter::DB.3 \
		Data::Printer::Filter::DateTime.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
BUILD_DEPENDS+=	p5-Term-ANSIColor>=3:${PORTSDIR}/devel/p5-Term-ANSIColor
RUN_DEPENDS+=	p5-Term-ANSIColor>=3:${PORTSDIR}/devel/p5-Term-ANSIColor
.endif

.include <bsd.port.post.mk>

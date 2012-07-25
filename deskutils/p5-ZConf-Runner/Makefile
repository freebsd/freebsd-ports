# New ports collection makefile for:	p5-ZConf-Runner
# Date created:		2009-01-14
# Whom:			Zane C, Bowers <vvelox@vvelox.net>
#
# $FreeBSD$
#

PORTNAME=	ZConf-Runner
PORTVERSION=	2.1.4
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Run a file using a chosen method, desktop entry, or mimetype

BUILD_DEPENDS=	p5-ZConf>=6.1.0:${PORTSDIR}/net/p5-ZConf \
		p5-File-MimeInfo>=0.16:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-Curses-UI>=0.9609:${PORTSDIR}/devel/p5-Curses-UI \
		p5-ZConf-GUI>=1.0.3:${PORTSDIR}/devel/p5-ZConf-GUI \
		p5-String-ShellQuote>=1.04:${PORTSDIR}/textproc/p5-String-ShellQuote
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		ZConf::Runner.3 \
		ZConf::Runner::GUI.3 \
		ZConf::Runner::GUI::Curses.3

.include <bsd.port.mk>

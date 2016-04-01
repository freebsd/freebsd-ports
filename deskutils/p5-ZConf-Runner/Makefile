# Created by: Zane C, Bowers <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	ZConf-Runner
PORTVERSION=	2.1.4
PORTREVISION=	2
CATEGORIES=	deskutils perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:VVELOX
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Run a file using a chosen method, desktop entry, or mimetype

BUILD_DEPENDS=	p5-ZConf>=6.1.0:net/p5-ZConf \
		p5-File-MimeInfo>=0.16:devel/p5-File-MimeInfo \
		p5-Curses-UI>=0.9609:devel/p5-Curses-UI \
		p5-ZConf-GUI>=1.0.3:devel/p5-ZConf-GUI \
		p5-String-ShellQuote>=1.04:textproc/p5-String-ShellQuote
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5 shebangfix
SHEBANG_FILES=	bin/zcrunner
USE_PERL5=	configure

.include <bsd.port.mk>

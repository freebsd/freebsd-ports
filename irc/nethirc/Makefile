# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	NetHirc
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/nethirc/

MAINTAINER=	matt_mills@btopenworld.com
COMMENT=	Perl-based IRC client that uses Net::IRC

BUILD_DEPENDS=	p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC \
		p5-String-Format>=0:textproc/p5-String-Format \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>

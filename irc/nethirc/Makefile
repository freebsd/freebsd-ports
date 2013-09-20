# Created by: Will Andrews <andrews@technologist.com>
# $FreeBSD$

PORTNAME=	NetHirc
PORTVERSION=	0.94
CATEGORIES=	irc
MASTER_SITES=	ftp://ftp.nog.net/pub/tony/nethirc/

MAINTAINER=	matt_mills@btopenworld.com
COMMENT=	Perl-based IRC client that uses Net::IRC

BUILD_DEPENDS=	p5-POE-Component-IRC>=0:${PORTSDIR}/irc/p5-POE-Component-IRC \
		p5-String-Format>=0:${PORTSDIR}/textproc/p5-String-Format \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN1=		nethirc.pl.1
MAN3=		NetHirc.3

NO_STAGE=	yes
.include <bsd.port.mk>

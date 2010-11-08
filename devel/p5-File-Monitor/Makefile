# New ports collection makefile for:	p5-File-Monitor
# Date created:		2007-12-29
# Whom:			Masahiro Teramoto <markun@onohara.to>
#
# $FreeBSD$
#

PORTNAME=	File-Monitor
PORTVERSION=	1.00
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	markun@onohara.to
COMMENT=	Monitor files and directories for changes

BUILD_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version
RUN_DEPENDS=	p5-version>=0:${PORTSDIR}/devel/p5-version

PERL_CONFIGURE=	yes

MAN3=		File::Monitor::Base.3 \
		File::Monitor.3 \
		File::Monitor::Delta.3 \
		File::Monitor::Object.3

.include <bsd.port.mk>

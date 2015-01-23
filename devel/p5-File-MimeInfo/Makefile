# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	File-MimeInfo
PORTVERSION=	0.26
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Determine file type

BUILD_DEPENDS=	p5-File-BaseDir>=0.03:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-File-DesktopEntry>=0.04:${PORTSDIR}/devel/p5-File-DesktopEntry
RUN_DEPENDS:=	p5-File-BaseDir>=0.03:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-File-DesktopEntry>=0.04:${PORTSDIR}/devel/p5-File-DesktopEntry \
		update-mime-database:${PORTSDIR}/misc/shared-mime-info

USES=		perl5
USE_PERL5=	configure

regression-test:
	cd ${WRKSRC} && ${MAKE} test

.include <bsd.port.mk>

# Created by: Rong-En Fan <rafan@infor.org>
# $FreeBSD$

PORTNAME=	File-MimeInfo
PORTVERSION=	0.16
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Determine file type

BUILD_DEPENDS=	p5-File-BaseDir>=0.03:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-File-DesktopEntry>=0.04:${PORTSDIR}/devel/p5-File-DesktopEntry
RUN_DEPENDS:=	p5-File-BaseDir>=0.03:${PORTSDIR}/devel/p5-File-BaseDir \
		p5-File-DesktopEntry>=0.04:${PORTSDIR}/devel/p5-File-DesktopEntry \
		${LOCALBASE}/share/mime/magic:${PORTSDIR}/misc/shared-mime-info

USES=		perl5
USE_PERL5=	modbuild

MAN1=		mimetype.1 mimeopen.1
MAN3=		File::MimeInfo::Applications.3 \
		File::MimeInfo::Cookbook.3 \
		File::MimeInfo::Magic.3 \
		File::MimeInfo::Rox.3 \
		File::MimeInfo.3

regression-test:
	cd ${WRKSRC} && ${PERL5} ${PL_BUILD} test

.include <bsd.port.mk>

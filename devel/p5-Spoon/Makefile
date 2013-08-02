# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	Spoon
PORTVERSION=	0.24
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Spiffy Application Building Framework

BUILD_DEPENDS=	p5-Spiffy>=0:${PORTSDIR}/devel/p5-Spiffy \
		p5-IO-All>=0:${PORTSDIR}/devel/p5-IO-All \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Spoon.3 \
		Spoon::Base.3 \
		Spoon::CGI.3 \
		Spoon::Command.3 \
		Spoon::ContentObject.3 \
		Spoon::Cookie.3 \
		Spoon::DataObject.3 \
		Spoon::Formatter.3 \
		Spoon::Hooks.3 \
		Spoon::Hub.3 \
		Spoon::Installer.3 \
		Spoon::MetadataObject.3 \
		Spoon::Plugin.3 \
		Spoon::Registry.3 \
		Spoon::Template.3 \
		Spoon::Template::TT2.3 \
		Spoon::Utils.3 \
		Spoon::Config.3

.if !defined(NOPORTDOCS)
PORTDOCS=	Changes README

post-install:
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.include <bsd.port.mk>

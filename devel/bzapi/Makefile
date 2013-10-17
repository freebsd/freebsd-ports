# $FreeBSD$

PORTNAME=	bzapi
DISTVERSION=	165:82e75bdd00be
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/pgollucci

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Bugzilla REST API

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.80011:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Plugin-ConfigLoader>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-ConfigLoader \
		p5-Catalyst-Plugin-Static-Simple>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Static-Simple \
		p5-Catalyst-Action-RenderView>=0:${PORTSDIR}/www/p5-Catalyst-Action-RenderView \
		p5-BZ-Client>=0:${PORTSDIR}/devel/p5-BZ-Client \
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose \
		p5-Catalyst-Action-REST>=0:${PORTSDIR}/www/p5-Catalyst-Action-REST \
		p5-Catalyst-Plugin-Log-Handler>=0.08:${PORTSDIR}/www/p5-Catalyst-Plugin-Log-Handler \
		p5-parent>=0:${PORTSDIR}/devel/p5-parent \
		p5-Config-General>=0:${PORTSDIR}/devel/p5-Config-General \
		p5-Catalyst-Devel>=0:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Module-Install>=0:${PORTSDIR}/devel/p5-Module-Install \
		p5-Text-CSV_XS>=0:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Slurp>=0:${PORTSDIR}/devel/p5-Slurp \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-Data-Walk>=0:${PORTSDIR}/devel/p5-Data-Walk \
		bugzilla40>=4.0.0:${PORTSDIR}/devel/bugzilla40
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
WRKSRC=	${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/script/*.pl	${STAGEDIR}${PREFIX}/bin
	@(cd ${WRKSRC}/extension/BzAPI; ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/bugzilla/extensions/BzAPI)
	@(cd ${WRKSRC}/lib/Bugzilla; ${COPYTREE_SHARE} . ${STAGEDIR}${SITE_PERL}/Bugzilla)

.include <bsd.port.mk>

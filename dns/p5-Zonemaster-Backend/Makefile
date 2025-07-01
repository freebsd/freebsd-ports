PORTNAME=	Zonemaster-Backend
DISTVERSION=	11.5.0
CATEGORIES=	dns perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ZNMSTR
PKGNAMEPREFIX=	p5-

MAINTAINER=	dch@FreeBSD.org
COMMENT=	Perl backend for Zonemaster DNS testing
WWW=		https://zonemaster.net/en

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE
BUILD_DEPENDS=	p5-Devel-CheckLib>0:devel/p5-Devel-CheckLib \
		p5-Module-Install>0:devel/p5-Module-Install
RUN_DEPENDS=	jq>0:textproc/jq \
		p5-Class-Method-Modifiers>=0:devel/p5-Class-Method-Modifiers \
		p5-Config-IniFiles>=0:devel/p5-Config-IniFiles \
		p5-Daemon-Control>=0:devel/p5-Daemon-Control \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite \
		p5-DBI>=0:databases/p5-DBI \
		p5-File-ShareDir>=0:devel/p5-File-ShareDir \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-JSON-RPC>=0:devel/p5-JSON-RPC \
		p5-JSON-Validator>=0:textproc/p5-JSON-Validator \
		p5-Locale-libintl>=0:devel/p5-Locale-libintl \
		p5-Log-Any-Adapter-Dispatch>=0:devel/p5-Log-Any-Adapter-Dispatch \
		p5-Log-Any>=0:devel/p5-Log-Any \
		p5-Log-Dispatch>=0:devel/p5-Log-Dispatch \
		p5-Mojolicious>=0:www/p5-Mojolicious \
		p5-Moose>=0:devel/p5-Moose \
		p5-Parallel-ForkManager>=0:devel/p5-Parallel-ForkManager \
		p5-Plack-Middleware-ReverseProxy>=0:www/p5-Plack-Middleware-ReverseProxy \
		p5-Plack>=0:www/p5-Plack \
		p5-Role-Tiny>=0:devel/p5-Role-Tiny \
		p5-Router-Simple>=0:www/p5-Router-Simple \
		p5-Starman>=0:www/p5-Starman \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-Zonemaster-Engine>0:dns/p5-Zonemaster-Engine


USES=		gmake localbase perl5
USE_PERL5=	configure

USERS=		zonemaster
GROUPS=		zonemaster

post-extract:
	${REINPLACE_CMD} -i '' \
		-e '/[[:<:]]database_file[[:>:]]/ s:=.*:= /var/db/zonemaster/db.sqlite:' \
		-e '/[[:<:]]log_file[[:>:]]/ s:=.*:= /var/log/zonemaster/backend.log:' \
		${WRKSRC}/share/backend_config.ini
	${REINPLACE_CMD} -i '' -e 's:/usr/local:${LOCALBASE}:g' \
		${WRKSRC}/share/zm_rpcapi-bsd \
		${WRKSRC}/share/zm_testagent-bsd

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/zonemaster \
		${STAGEDIR}/var/db/zonemaster \
		${STAGEDIR}/var/log/zonemaster \
		${STAGEDIR}/var/run/zonemaster
	${INSTALL_DATA} ${WRKSRC}/share/backend_config.ini ${STAGEDIR}${PREFIX}/etc/zonemaster/backend_config.ini.sample
	${INSTALL_SCRIPT} ${WRKSRC}/share/zm_rpcapi-bsd ${STAGEDIR}${PREFIX}/etc/rc.d/zm_rpcapi
	${INSTALL_SCRIPT} ${WRKSRC}/share/zm_testagent-bsd ${STAGEDIR}${PREFIX}/etc/rc.d/zm_testagent

.include <bsd.port.mk>

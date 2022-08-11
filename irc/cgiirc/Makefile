PORTNAME=	cgiirc
PORTVERSION=	0.5.12
CATEGORIES=	irc www perl5
MASTER_SITES=	http://cgiirc.org/releases/ \
		SF/${PORTNAME}/cgi-irc/${PORTVERSION}

MAINTAINER=	rodrigo@FreeBSD.org
COMMENT=	IRC web gateway written in Perl

LICENSE=	GPLv2

USES=		cpe perl5 shebangfix
NO_BUILD=	yes
SHEBANG_FILES=	docs/identd.pl \
		irc.cgi \
		client-perl.cgi \
		nph-irc.cgi
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

pre-install:
	@${MV} ${WRKSRC}/cgiirc.config ${WRKSRC}/cgiirc.config.sample

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/www/cgiirc
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/www/cgiirc

.include <bsd.port.mk>

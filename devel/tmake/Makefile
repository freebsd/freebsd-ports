PORTNAME=	tmake
PORTVERSION=	2.12
CATEGORIES=	devel perl5
MASTER_SITES=	SF \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Extremely portable perl-based make utility
WWW=		https://tmake.sourceforge.net/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Last release in 2004 and dead upstream, superseded by qmake
EXPIRATION_DATE=2023-12-31

USES=		perl5 shebangfix zip

NO_ARCH=	yes
NO_BUILD=	yes

SHEBANG_FILES=	bin/progen bin/tmake

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' ${WRKSRC}/lib/freebsd-g++/tmake.conf

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/
	cd ${WRKSRC}/bin/ && ${INSTALL_SCRIPT} progen tmake ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/lib/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ '! -name *.bak -and ! -name *.orig'
	@${ECHO_MSG}
	@${ECHO_MSG} "Make sure to set your TMAKEPATH environment variable to ${DATADIR}/freebsd-g++"
	@${ECHO_MSG}

.include <bsd.port.mk>

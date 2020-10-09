# Created by: Chris Petrik <chris@officialunix.com>
# $FreeBSD$

PORTNAME=	diakonos
DISTVERSIONPREFIX=	v
DISTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	editors ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Console editor for the masses

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENCE

RUN_DEPENDS=	rubygem-curses>=1.3.1:devel/rubygem-curses

USES=		shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	Pistos
USE_RUBY=	yes
SHEBANG_FILES=	bin/${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	installation.rb
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/installation.rb \
		${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/diakonos.conf \
		${STAGEDIR}${PREFIX}/etc/diakonos.conf.sample
	${INSTALL_DATA} ${WRKSRC}/diakonos-256-colour.conf \
		${STAGEDIR}${PREFIX}/etc/diakonos-256-colour.conf.sample

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/help
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG README.rdoc \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/help/*.dhf ${STAGEDIR}${DOCSDIR}/help

.include <bsd.port.mk>

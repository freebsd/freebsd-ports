# Created by: Chris Petrik <chris@officialunix.com>
# $FreeBSD$

PORTNAME=	diakonos
PORTVERSION=	0.9.1
CATEGORIES=	editors ruby
MASTER_SITES=	http://diakonos.pist0s.ca/archives/ \
		http://distfiles.bsdjunk.com
MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux editor for the masses

LICENSE=	MIT

USE_RUBY=	yes

NO_BUILD=	yes
SUB_FILES=	installation.rb
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin/env ruby|${RUBY}|g' ${WRKSRC}/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${STAGEDIR}${RUBY_SITELIBDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/installation.rb \
		${STAGEDIR}${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/diakonos.conf \
		${STAGEDIR}${PREFIX}/etc/diakonos.conf.dist
	${INSTALL_DATA} ${WRKSRC}/diakonos-256-colour.conf \
		${STAGEDIR}${PREFIX}/etc/diakonos-256-colour.conf.dist
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/help
	(cd ${WRKSRC} && ${INSTALL_DATA} CHANGELOG LICENCE README.rdoc \
		${STAGEDIR}${DOCSDIR})
	${INSTALL_DATA} ${WRKSRC}/help/*.dhf ${STAGEDIR}${DOCSDIR}/help

.include <bsd.port.mk>

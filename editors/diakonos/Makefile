# New ports collection makefile for:    diakonos
# Date created:         30 June 2009
# Whom:                 chris@officialunix.com
#
# $FreeBSD$
#

PORTNAME=	diakonos
PORTVERSION=	0.8.12
CATEGORIES=	editors ruby
MASTER_SITES=	http://purepistos.net/diakonos/ \
		http://distfiles.officialunix.com/

MAINTAINER=	chris@officialunix.com
COMMENT=	A Linux editor for the masses

USE_RUBY=	yes
RUBY_VER=	1.9

NO_BUILD=	yes
SUB_FILES=	installation.rb
SUB_LIST=	RUBY_SITELIBDIR=${RUBY_SITELIBDIR}

post-patch:
	@${REINPLACE_CMD} 's|/usr/bin/env ruby|${RUBY}|g' ${WRKSRC}/bin/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/${PORTNAME} ${PREFIX}/bin/
	${MKDIR} ${RUBY_SITELIBDIR}/${PORTNAME}
	cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${RUBY_SITELIBDIR}/
	${INSTALL_SCRIPT} ${WRKDIR}/installation.rb ${RUBY_SITELIBDIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/diakonos.conf ${PREFIX}/etc/diakonos.conf.dist; \
	if [ ! -f ${PREFIX}/etc/diakonos.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/diakonos.conf.dist ${PREFIX}/etc/diakonos.conf; \
	fi
	${INSTALL_DATA} ${WRKSRC}/diakonos-256-colour.conf ${PREFIX}/etc/diakonos-256-colour.conf.dist; \
	if [ ! -f ${PREFIX}/etc/diakonos-256-colour.conf ]; then \
		${INSTALL_DATA} ${PREFIX}/etc/diakonos-256-colour.conf.dist ${PREFIX}/etc/diakonos-256-colour.conf; \
	fi

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}/help
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/LICENCE ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/help/*.dhf ${DOCSDIR}/help/
.endif

.include <bsd.port.mk>

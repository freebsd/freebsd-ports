# ex:ts=8
# Ports collection makefile for:	tpg
# Date created:			Mar 15, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tpg
PORTVERSION=	2.0.3
CATEGORIES=	devel python
MASTER_SITES=	http://christophe.delord.free.fr/soft/tpg/
DISTNAME=	${PORTNAME:U}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tpg.py ${PYTHONPREFIX_SITELIBDIR}
	${LN} -fs ${PYTHONPREFIX_SITELIBDIR}/tpg.py ${PREFIX}/bin/tpg
.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/TPG/tpg_grammar.g ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/TPG/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

# ex:ts=8
# Ports collection makefile for:	py-bison
# Date created:			Aug 23, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	bison
PORTVERSION=	0.1.8
PORTREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	http://www.freenet.org.nz/python/pybison/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	py${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python-based parsing at the speed of C

BUILD_DEPENDS=	pyrex>=0.9.6.2:${PORTSDIR}/devel/pyrex

USE_BISON=	both
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGVERSION=	0.1

.if !defined(NOPORTDOCS)
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX}${PORTNAME}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		Does not compile on ia64
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${FIND} ${DOCSDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${DOCSDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.post.mk>

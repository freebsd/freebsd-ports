# ex:ts=8
# Ports collection makefile for:	f2py
# Date created:			Jun 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	f2py
PORTVERSION=	2.45.241.1926
CATEGORIES=	lang python
MASTER_SITES=	http://cens.ioc.ee/projects/f2py2e/2.x/
DISTNAME=	${PORTNAME:U}-${PORTVERSION:R}_${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fortran to Python Interface Generator

RUN_DEPENDS=	${PYNUMERIC}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/f2py
MAN1=		f2py.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/f2py.1 ${MAN1PREFIX}/man/man1
	@${FIND} ${PYTHON_SITELIBDIR}/f2py2e ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/f2py2e -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/docs/ ${DOCSDIR}
.endif

.include <bsd.port.mk>

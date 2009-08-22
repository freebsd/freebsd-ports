# ex:ts=8
# New ports collection makefile for:    happydoc
# Date created:         Dec 29, 2000
# Whom:                 Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	happydoc
PORTVERSION=	3.0.a1
CATEGORIES=	devel python
MASTER_SITES=	SF/${PORTNAME}/HappyDoc/3.0
DISTNAME=	HappyDoc_r${PORTVERSION:S/./_/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool for extracting documentation from Python source code

USE_PYTHON=	yes
WRKSRC=		${WRKDIR}/HappyDoc3-r${PORTVERSION:S/./_/g}
NO_BUILD=	yes
PLIST_FILES=	bin/happydoc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/happydoc ${PREFIX}/bin
	@${CP} -R ${WRKSRC}/happydoclib ${PYTHON_SITELIBDIR}
	@${FIND} ${PYTHON_SITELIBDIR}/happydoclib -type f | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/happydoclib -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>

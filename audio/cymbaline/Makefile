# New ports collection makefile for:	cymbaline
# Date created:			Jun 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cymbaline
PORTVERSION=	1.2f
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/files/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Console frontend for mpg123

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		aumix:${PORTSDIR}/audio/aumix \
		${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao \
		${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

PLIST_FILES=	bin/cymbaline

post-install:
	@${MV} -f ${PREFIX}/bin/cymbaline.py ${PREFIX}/bin/cymbaline
	@${FIND} ${PYTHON_SITELIBDIR}/cypack ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/cypack -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

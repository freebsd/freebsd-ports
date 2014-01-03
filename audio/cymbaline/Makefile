# Created by: ijliao
# $FreeBSD$

PORTNAME=	cymbaline
PORTVERSION=	1.3e
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/files/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	Console frontend for py-mad

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/aomodule.so:${PORTSDIR}/audio/py-ao \
		${PYTHON_SITELIBDIR}/madmodule.so:${PORTSDIR}/audio/py-mad

NO_STAGE=	yes
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PLIST_FILES=	bin/cymbaline

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	*
.endif

post-install:
	@${MV} -f ${PREFIX}/bin/cymbaline.py ${PREFIX}/bin/cymbaline
	@${FIND} ${PYTHON_SITELIBDIR}/cypack ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PYTHON_SITELIBDIR}/cypack -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

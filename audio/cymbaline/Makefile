# ex:ts=8
# New ports collection makefile for:	cymbaline
# Date created:			Jun 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cymbaline
PORTVERSION=	1.2b
PORTREVISION=	0
CATEGORIES=	audio python
MASTER_SITES=	http://www.silmarill.org/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	mpg123 console frontend

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		aumix:${PORTSDIR}/audio/aumix

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

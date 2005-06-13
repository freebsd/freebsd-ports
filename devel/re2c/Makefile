# New ports collection makefile for:	re2c
# Date created:		14 May 1998
# Whom:			Eivind Eklund <eivind@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	re2c
PORTVERSION=	0.9.7
PORTREVISION=	0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Compile regular expression to C (much faster final code than flex)

GNU_CONFIGURE=	yes
USE_GCC=	3.4+

PLIST_FILES=	bin/re2c
MAN1=		re2c.1

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/ ${DOCSDIR}
	@${MKDIR} ${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}
	@${FIND} ${EXAMPLESDIR} ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${EXAMPLESDIR} -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif

.include <bsd.port.mk>

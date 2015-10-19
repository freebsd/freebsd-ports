# Created by: Nicola Vitale <nivit@email.it>
# $FreeBSD$

PORTNAME=	arabtex
PORTVERSION=	3.11
PORTREVISION=	5
CATEGORIES=	arabic print
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/${PORTNAME}/
DISTNAME=	arab${PORTVERSION:S/.//}
EXTRACT_SUFX=	.tgz

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TeX/LaTeX package to generate Arabic writing

LICENSE=	LPPL10

USE_TEX=	base texmf

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

ARABTEXDIRS=	fonts tex
MKTEXLSR=	${LOCALBASE}/bin/mktexlsr

PLIST_SUB=	MKTEXLSR=${MKTEXLSR}

OPTIONS_DEFINE=	DOCS

DOCS_VARS=	ARABTEXDIRS+=doc

do-install:
.for dir in ${ARABTEXDIRS}
	@${MKDIR} ${STAGEDIR}${PREFIX}/${TEXMFLOCALDIR}/${dir}
	(cd ${WRKDIR}/${dir} && \
	${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${TEXMFLOCALDIR}/${dir})
.endfor

.include <bsd.port.mk>

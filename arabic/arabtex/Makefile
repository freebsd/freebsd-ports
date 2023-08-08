PORTNAME=	arabtex
PORTVERSION=	3.11
PORTREVISION=	7
CATEGORIES=	arabic print
MASTER_SITES=	ftp://ftp.informatik.uni-stuttgart.de/pub/${PORTNAME}/
DISTNAME=	arab${PORTVERSION:S/.//}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	TeX/LaTeX package to generate Arabic writing
WWW=		http://www2.informatik.uni-stuttgart.de/ivi/bs/research/arab_e.htm

LICENSE=	LPPL10

USES=		tar:tgz tex
USE_TEX=	base # texmf

NO_WRKSUBDIR=	yes
NO_BUILD=	yes

PLIST_SUB=	MKTEXLSR=${LOCALBASE}/bin/mktexlsr

OPTIONS_DEFINE=	DOCS

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "fonts tex" \
		${STAGEDIR}${PREFIX}/${TEXMFLOCALDIR})

do-install-DOCS-on:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} doc \
		${STAGEDIR}${PREFIX}/${TEXMFLOCALDIR})

.include <bsd.port.mk>

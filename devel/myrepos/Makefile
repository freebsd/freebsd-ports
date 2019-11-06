# $FreeBSD$

PORTNAME=	myrepos
PORTVERSION=	1.20160123
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	jonathan@FreeBSD.org
COMMENT=	Tool to manage all your version control repos

BROKEN=		unfetchable

LICENSE=	GPLv2+

USE_GITHUB=	yes
GH_ACCOUNT=	joeyh

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	mr

PLIST_FILES=	bin/mr
PORTDOCS=	*

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mr ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>

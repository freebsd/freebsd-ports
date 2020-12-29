# $FreeBSD$

PORTNAME=	myrepos
PORTVERSION=	1.20180726
CATEGORIES=	devel
MASTER_SITES=	https://git.joeyh.name/index.cgi/mr.git/snapshot/ \
		https://git.kitenet.net/index.cgi/mr.git/snapshot/
DISTNAME=	mr-${PORTVERSION}

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tool to manage all your version control repos

LICENSE=	GPLv2+

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	mr

DOCLIST=	README mrconfig mrconfig.complex

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mr ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
	(cd ${WRKSRC} && ${INSTALL_DATA} ${DOCLIST} ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/doc/ && ${CAT} index.mdwn > ${STAGEDIR}${DOCSDIR}/HOWTO)
	(mkdir ${STAGEDIR}${DOCSDIR}/EXAMPLES && cd ${WRKSRC}/lib && \
	${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/EXAMPLES)

.include <bsd.port.mk>

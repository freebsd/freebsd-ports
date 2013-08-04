# Created by: William Grzybowski <wg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	defusedxml
PORTVERSION=	0.4.1
CATEGORIES=	devel python textproc
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	XML bomb protection for Python stdlib modules

LICENSE=	PSFL

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes

PORTDOCS=	*
DOCS_FILES=	CHANGES.txt README.txt

OPTIONS_DEFINE=	DOCS

.include <bsd.port.pre.mk>

post-install:
.if ${PYTHON_REL} >= 320
.include "${PORTSDIR}/devel/py-virtualenv/files/py3k-fix-pkg-plist.inc"
.endif

.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${DOCS_FILES:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

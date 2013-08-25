# $FreeBSD$

PORTNAME=	git-review
PORTVERSION=	1.23
CATEGORIES=	devel python
MASTER_SITES=	CHEESESHOP
MASTER_SITE_SUBDIR=	source/g/${PORTNAME}

MAINTAINER=	dereckson@gmail.com
COMMENT=	Allow to push review and interact with a Gerrit server

LICENSE=	AL2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse \
		git:${PORTSDIR}/devel/git

USE_PYTHON=	yes
NO_BUILD=	yes

MAN1=		git-review.1

.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-review ${PREFIX}/bin/git-review
	${INSTALL_MAN} ${WRKSRC}/git-review.1 ${PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/README.rst ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/HACKING.rst ${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/AUTHORS ${DOCSDIR}
.endif

.include <bsd.port.mk>

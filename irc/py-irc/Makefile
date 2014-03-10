# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	irc
PORTVERSION=	8.5.4
CATEGORIES=	irc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	wg@FreeBSD.org
COMMENT=	IRC protocol client library for Python

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:${PORTSDIR}/devel/py-six
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}hgtools>0:${PORTSDIR}/devel/py-hgtools \
		${PYTHON_PKGNAMEPREFIX}pytest-runner>0:${PORTSDIR}/devel/py-pytest-runner

USE_PYTHON=	yes
USE_PYDISTUTILS=easy_install
PYDISTUTILS_AUTOPLIST=	yes
USES=		zip

PORTEXAMPLES=	irccat.py irccat2.py servermap.py testbot.py \
		dccreceive.py dccsend.py
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 270
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}argparse>0:${PORTSDIR}/devel/py-argparse
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|license="MIT",|license="MIT", zip_safe=False,|' ${WRKSRC}/setup.py
	${CHMOD} -R o-w ${WRKSRC}/irc.egg-info

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${PORTEXAMPLES:S,^,${WRKSRC}/scripts/,} ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.post.mk>

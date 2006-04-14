# New ports collection makefile for:	buildbot
# Date created:		27 Sep 2005
# Whom:			Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	buildbot
PORTVERSION=	0.7.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automated system from compile/test cycle to validate code changes

RUN_DEPENDS=	mktap:${PORTSDIR}/devel/py-twisted

USE_REINPLACE=	yes
USE_PYTHON=	2.2+
NO_BUILD=	yes

post-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} -n 10 ${REINPLACE_CMD} -e \
		's|/usr/bin/python|${LOCALBASE}/bin/python|g'

do-install:
	@cd ${WRKSRC} && ${PYTHON_CMD} setup.py install --prefix=${PREFIX}

.include <bsd.port.mk>

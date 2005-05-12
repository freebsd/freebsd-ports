# New ports collection makefile for:	A-A-P GUI IDE: agide
# Date created:				26 August 2003
# Whom:					Rui Lopes <rui@ruilopes.com>
#
# $FreeBSD$
#

PORTNAME=	agide
PORTVERSION=	0.121
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	a-a-p

MAINTAINER=	rui@ruilopes.com
COMMENT=	A-A-P GUI IDE: a framework for software development

RUN_DEPENDS=	${LOCALBASE}/bin/aap:${PORTSDIR}/devel/aap \
		${LOCALBASE}/bin/vim:${PORTSDIR}/editors/vim \
		${PYTHON_SITELIBDIR}/wxPython/__init__.py:${PORTSDIR}/x11-toolkits/py-wxPython24

MAN1=		agide.1

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

USE_ZIP=	yes
USE_PYTHON=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}

pre-install:
	@${SH} ${FILESDIR}/check_vim

do-install:
	@cd ${WRKSRC} && \
		${PREFIX}/bin/aap PREFIX="${PREFIX}" install

.include <bsd.port.mk>

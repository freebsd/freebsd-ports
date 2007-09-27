# Ports collection makefile for:	bazaar-ng
# Date created:		10 October 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bazaar-ng
PORTVERSION=	0.91
CATEGORIES=	devel
MASTER_SITES=	http://bazaar-vcs.org/releases/src/
MASTER_SITE_SUBDIR=	gnu-arch
DISTNAME=	bzr-${PORTVERSION}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system by Canonical

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree

OPTIONS=	SFTP "Enable Paramiko for SFTP support" on

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr
PYDISTUTILS_PKGVERSION=	${PORTVERSION}.0

MAN1=		bzr.1

.include <bsd.port.pre.mk>

.if defined(WITH_SFTP)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/paramiko/__init__.py:${PORTSDIR}/security/py-paramiko
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${MAN1PREFIX}/man/man1

test:	build
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.post.mk>

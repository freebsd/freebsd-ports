# Ports collection makefile for:	bazaar-ng
# Date created:		10 October 2005
# Whom:			Ulf Lilleengen
#
# $FreeBSD$
#

PORTNAME=	bazaar-ng
PORTVERSION=	2.0.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/32236501/
DISTNAME=	bzr-${PORTVERSION}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system by Canonical

# Often not needed, but it's cheap insurance
BUILD_DEPENDS=	pyrexc:${PORTSDIR}/devel/pyrex

OPTIONS=	SFTP "Enable Paramiko for SFTP support" on

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr

MAN1=		bzr.1

.include <bsd.port.pre.mk>

# Included in 2.5
.if (${PYTHON_VERSION} == python2.4)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/cElementTree.so:${PORTSDIR}/devel/py-celementtree
.endif

.if !defined(WITHOUT_SFTP)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/paramiko/__init__.py:${PORTSDIR}/security/py-paramiko
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${MAN1PREFIX}/man/man1/

test:	build
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.post.mk>

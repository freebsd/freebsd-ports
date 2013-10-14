# Created by: Ulf Lilleengen
# $FreeBSD$

PORTNAME=	bzr
PORTVERSION=	2.6.0
CATEGORIES=	devel
MASTER_SITES=	https://launchpadlibrarian.net/145980211/
DISTNAME=	bzr-${PORTVERSION}

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Distributed version control system by Canonical

# Often not needed, but it's cheap insurance
BUILD_DEPENDS=	cython:${PORTSDIR}/lang/cython

OPTIONS_DEFINE=	SFTP CA_BUNDLE
SFTP_DESC=	Paramiko for SFTP support
CA_BUNDLE_DESC=	Include CA bundle for SSL cert validation
OPTIONS_DEFAULT=	SFTP CA_BUNDLE

USE_PYTHON=	2.6+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	bzr
USES=		gettext

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSFTP}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}paramiko>=0:${PORTSDIR}/security/py-paramiko
.endif

.if ${PORT_OPTIONS:MCA_BUNDLE}
RUN_DEPENDS+=	${LOCALBASE}/share/certs/ca-root-nss.crt:${PORTSDIR}/security/ca_root_nss
.endif

post-install:
	${INSTALL_MAN} ${WRKSRC}/bzr.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

test:	build
	cd ${WRKSRC} && ./bzr selftest

.include <bsd.port.mk>

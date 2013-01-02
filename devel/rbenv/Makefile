# $FreeBSD$

PORTNAME=	rbenv
PORTVERSION=	0.3.0
CATEGORIES=	devel ruby
MASTER_SITES=	GH

MAINTAINER=	fmb@onibox.net
COMMENT=	Manage multiple versions of ruby

LICENSE=	RBENV
LICENSE_NAME=	Sam Stephenson
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	${_LICENSE_PERMS_DEFAULT}

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	sstephenson
GH_PROJECT=	rbenv
GH_COMMIT=	b10bdb1
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-local-exec ${PREFIX}/bin
	( cd ${WRKSRC}/libexec && ${COPYTREE_BIN} \* ${PREFIX}/libexec )
	@${LN} -sf ${PREFIX}/libexec/rbenv ${PREFIX}/bin/rbenv

.include <bsd.port.mk>

# $FreeBSD$

PORTNAME=	rbenv
PORTVERSION=	0.4.0
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
GH_COMMIT=	9375e99
GH_TAGNAME=	v${PORTVERSION}

NO_BUILD=	yes

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-local-exec ${PREFIX}/bin
	@( cd ${WRKSRC}/libexec && ${COPYTREE_BIN} \* ${PREFIX}/libexec )
	@${LN} -sf ${PREFIX}/libexec/rbenv ${PREFIX}/bin/rbenv
	@${MKDIR} ${DATADIR}/completions
	@( cd ${WRKSRC}/completions && ${COPYTREE_BIN} \* ${DATADIR}/completions )

.include <bsd.port.mk>

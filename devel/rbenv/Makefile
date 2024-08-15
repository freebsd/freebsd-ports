PORTNAME=	rbenv
PORTVERSION=	1.3.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Manage multiple versions of ruby
WWW=		https://rbenv.org/ \
		https://github.com/rbenv/rbenv

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	bash:shells/bash

USES=		cpe

USE_GITHUB=	yes

NO_ARCH=	yes
NO_BUILD=	yes
REINPLACE_ARGS=	-i ''

CPE_VENDOR=	rbenv_project

post-patch:
	@${REINPLACE_CMD} -e 's|$${root}/completions|${DATADIR}/completions|g' ${WRKSRC}/libexec/rbenv-init
	@-${RM} ${WRKSRC}/libexec/rbenv-init.bak

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/rbenv.d ${STAGEDIR}${DATADIR}/completions
	${INSTALL_SCRIPT} ${WRKSRC}/libexec/* ${STAGEDIR}${PREFIX}/libexec/
	${RLN} ${STAGEDIR}${PREFIX}/libexec/rbenv ${STAGEDIR}${PREFIX}/bin/rbenv
	cd ${WRKSRC}/rbenv.d && ${COPYTREE_BIN} . ${STAGEDIR}${PREFIX}/etc/rbenv.d
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/rbenv.1 ${STAGEDIR}${PREFIX}/share/man/man1/rbenv.1
	cd ${WRKSRC}/completions && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR}/completions

.include <bsd.port.mk>

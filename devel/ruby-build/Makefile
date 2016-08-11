# $FreeBSD$

PORTNAME=	ruby-build
PORTVERSION=	20160602
DISTVERSIONPREFIX=	v
CATEGORIES=	devel ruby

MAINTAINER=	meta+ports@vmeta.jp
COMMENT=	Compile and install different ruby versions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	autoconf>0:devel/autoconf \
		curl:ftp/curl \
		gmake:devel/gmake

OPTIONS_DEFINE=	RBENV
RBENV_DESC=	Install rbenv for installation support
OPTIONS_DEFAULT=	RBENV
RBENV_RUN_DEPENDS=	rbenv:devel/rbenv

USE_GITHUB=	yes
GH_ACCOUNT=	sstephenson

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/ruby-build \
		libexec/rbenv-install \
		libexec/rbenv-uninstall
PORTDATA=	*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-build ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-install ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-uninstall ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DATADIR}
	( cd ${WRKSRC}/share/ruby-build && ${COPYTREE_BIN} \* ${STAGEDIR}${DATADIR} )

.include <bsd.port.mk>

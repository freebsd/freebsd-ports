# $FreeBSD$

PORTNAME=	ruby-build
PORTVERSION=	20200520
DISTVERSIONPREFIX=	v
CATEGORIES=	devel ruby
DIST_SUBDIR=	rbenv

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Compile and install different ruby versions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# ruby-build builds Ruby so these are needed at run-time.
# warnings by portlint are not correct. keep this.
RUN_DEPENDS=	autoconf>0:devel/autoconf \
		curl:ftp/curl \
		gmake:devel/gmake

USE_GITHUB=	yes
GH_ACCOUNT=	rbenv

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/ruby-build \
		libexec/rbenv-install \
		libexec/rbenv-uninstall
PORTDATA=	*

OPTIONS_DEFINE=	RBENV
OPTIONS_DEFAULT=RBENV
RBENV_DESC=	Install rbenv for installation support
RBENV_RUN_DEPENDS=	rbenv:devel/rbenv

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-build ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-install ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/bin/rbenv-uninstall ${STAGEDIR}${PREFIX}/libexec
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/share/ruby-build && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

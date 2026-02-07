PORTNAME=	ruby-install
DISTVERSION=	0.10.1
CATEGORIES=	devel ruby
MASTER_SITES=	https://github.com/postmodern/ruby-install/releases/download/v${PORTVERSION}/

MAINTAINER=	henry@henryphan.com
COMMENT=	Compile and install different versions of Ruby
WWW=		https://github.com/postmodern/ruby-install

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash \
		curl:ftp/curl

USES=		sudo
NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-install ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/share/man/man1/ruby-install.1 ${STAGEDIR}${PREFIX}/share/man/man1
	(cd ${WRKSRC}/share/ruby-install && ${COPYTREE_BIN} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>

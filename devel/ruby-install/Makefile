PORTNAME=       ruby-install
PORTVERSION=    0.9.0
DISTVERSIONPREFIX=      v
CATEGORIES=     devel ruby

MAINTAINER=     henry@henryphan.com
COMMENT=        Compile and install different versions of Ruby
WWW=		https://github.com/postmodern/ruby-install

LICENSE=        MIT
LICENSE_FILE=   ${WRKSRC}/LICENSE.txt

RUN_DEPENDS=    bash:shells/bash curl:ftp/curl sudo:security/sudo

USE_GITHUB=	yes
GH_ACCOUNT=	postmodern

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/ruby-install ${STAGEDIR}${PREFIX}/bin
	( cd ${WRKSRC}/share/man/man1 && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/share/man/man1 )
	( cd ${WRKSRC}/share/ruby-install && ${COPYTREE_BIN} \* ${STAGEDIR}${PREFIX}/share/ruby-install )

.include <bsd.port.mk>

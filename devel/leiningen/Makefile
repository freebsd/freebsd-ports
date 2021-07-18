PORTNAME=	leiningen
PORTVERSION=	2.9.6
CATEGORIES=	devel lisp java
MASTER_SITES=	https://github.com/technomancy/leiningen/releases/download/${PORTVERSION}/:standalone
DISTFILES=	leiningen-${PORTVERSION}-standalone.zip:standalone
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automate Clojure projects

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	technomancy
USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/lein \
		etc/bash_completion.d/_lein.bash \
		share/man/man1/lein.1.gz \
		share/zsh/site-functions/_lein
PORTDATA=	leiningen-${PORTVERSION}-standalone.zip

post-patch:
	@${REINPLACE_CMD} -E -e 's|function (.*) \{|\1() {|' \
		-e '1s|^.*|#!/bin/sh|' \
		-e 's|/etc/leinrc|${PREFIX}/etc/leinrc|' \
		-e 's|\.leinrc|./&|' -e 's|source "|. "|' \
		-e 's|^if \[\[ (.*) \]\];|if [ \1 ];|' \
		-e 's|^LEIN_JAR=.*|LEIN_JAR=${DATADIR}/leiningen-${PORTVERSION}-standalone.zip|' \
		${WRKSRC}/bin/lein-pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lein-pkg \
		${STAGEDIR}${PREFIX}/bin/lein
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash_completion.bash \
		${STAGEDIR}${PREFIX}/etc/bash_completion.d/_lein.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh_completion.zsh \
		${STAGEDIR}${PREFIX}/share/zsh/site-functions/_lein
	${INSTALL_MAN} ${WRKSRC}/doc/lein.1 \
		${STAGEDIR}${PREFIX}/share/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/leiningen-${PORTVERSION}-standalone.zip \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

PORTNAME=	leiningen
DISTVERSION=	2.9.10
PORTREVISION=	1
CATEGORIES=	devel lisp java
MASTER_SITES=	https://codeber.org/technomancy/leiningen/releases/download/${PORTVERSION}/:standalone \
		https://codeberg.org/leiningen/leiningen/archive/:DEFAULT
DISTFILES=	${DISTVERSION}${EXTRACT_SUFX} ${PORTNAME}-${PORTVERSION}-standalone.jar:standalone
EXTRACT_ONLY=	${DISTVERSION}${EXTRACT_SUFX}


MAINTAINER=	ports@FreeBSD.org
COMMENT=	Automate Clojure projects

LICENSE=	EPL
LICENSE_FILE=	${WRKSRC}/COPYING

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/lein \
		etc/bash_completion.d/_lein.bash \
		share/man/man1/lein.1.gz \
		share/zsh/site-functions/_lein
PORTDATA=	leiningen-${PORTVERSION}-standalone.jar

post-patch:
	@${REINPLACE_CMD} -E -e 's|function (.*) \{|\1() {|' \
		-e '1s|^.*|#!/bin/sh|' \
		-e 's|/etc/leinrc|${PREFIX}/etc/leinrc|' \
		-e 's|\.leinrc|./&|' -e 's|source "|. "|' \
		-e 's|^if \[\[ (.*) \]\];|if [ \1 ];|' \
		-e 's|^LEIN_JAR=.*|LEIN_JAR=${DATADIR}/leiningen-${PORTVERSION}-standalone.jar|' \
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
	${INSTALL_DATA} ${DISTDIR}/leiningen-${PORTVERSION}-standalone.jar \
		${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

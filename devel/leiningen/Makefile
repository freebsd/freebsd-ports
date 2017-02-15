# $FreeBSD$

PORTNAME=	leiningen
PORTVERSION=	2.7.1
CATEGORIES=	devel lisp java
MASTER_SITES=	GH:source1 \
		https://github.com/technomancy/leiningen/releases/download/${PORTVERSION}/:source2
DISTFILES=	${DISTNAME}.tar.gz:source1 \
		leiningen-${PORTVERSION}-standalone.zip:source2
EXTRACT_ONLY=	${DISTNAME}.tar.gz

MAINTAINER=	tobik@FreeBSD.org
COMMENT=	Automate Clojure projects

LICENSE=	EPL

USE_GITHUB=	yes
GH_ACCOUNT=	technomancy

USES=		shebangfix
USE_JAVA=	yes
JAVA_VERSION=	1.6+
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/lein \
		etc/bash_completion.d/_lein.bash \
		man/man1/lein.1.gz \
		share/zsh/site-functions/_lein \
		%%JAVAJARDIR%%/leiningen.jar

SHEBANG_FILES=	bin/lein-pkg

post-patch:
	@${REINPLACE_CMD} -e "s|LEIN_JAR=.*|LEIN_JAR=${JAVAJARDIR}/leiningen.jar|" \
		${WRKSRC}/bin/lein-pkg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/lein-pkg ${STAGEDIR}${PREFIX}/bin/lein
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bash_completion.d
	${INSTALL_DATA} ${WRKSRC}/bash_completion.bash ${STAGEDIR}${PREFIX}/etc/bash_completion.d/_lein.bash
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/zsh/site-functions
	${INSTALL_DATA} ${WRKSRC}/zsh_completion.zsh ${STAGEDIR}${PREFIX}/share/zsh/site-functions/_lein
	${INSTALL_MAN} ${WRKSRC}/doc/lein.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/
	${INSTALL_DATA} ${DISTDIR}/leiningen-${PORTVERSION}-standalone.zip ${STAGEDIR}${JAVAJARDIR}/leiningen.jar

.include <bsd.port.mk>

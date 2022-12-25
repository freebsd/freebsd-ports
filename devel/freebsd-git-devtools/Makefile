PORTNAME=	freebsd-git-devtools
PORTVERSION=	20221107
CATEGORIES=	devel
MASTER_SITES=	https://cgit.freebsd.org/src/plain/tools/tools/git/
DISTFILES=	git-arc.sh?id=${_REV} \
		git-arc.1?id=${_REV} \
		mfc-candidates.sh?id=${_REV}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Simple Git tools from the FreeBSD src tree

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	arc:devel/arcanist \
		git:devel/git \
		jq:textproc/jq

EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	# empty
EXTRACT_AFTER_ARGS=	.
NO_ARCH=	yes
NO_BUILD=	yes

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/git-arc \
		bin/mfc-candidates \
		man/man1/git-arc.1.gz

_REV=		613aaf59afa307fc77c8eed01962a59423b1c5f3

post-patch:
	for f in ${WRKSRC}/*\?id=*; do \
		nn=$$(${ECHO_CMD} $$f | ${SED} -e s/\?id=.*//); ${MV} $$f $$nn; \
	done

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/git-arc.sh ${STAGEDIR}${PREFIX}/bin/git-arc
	${INSTALL_SCRIPT} ${WRKSRC}/mfc-candidates.sh ${STAGEDIR}${PREFIX}/bin/mfc-candidates
	${INSTALL_MAN} ${WRKSRC}/git-arc.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>

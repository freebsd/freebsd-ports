PORTNAME=	git-arc
PORTVERSION=	20211118
CATEGORIES=	devel
MASTER_SITES=	https://cgit.freebsd.org/src/plain/tools/tools/git/
DISTFILES=	${PORTNAME}.sh?id=${_REV} \
		${PORTNAME}.1?id=${_REV}
DIST_SUBDIR=	${PKGNAMEPREFIX}${PORTNAME}

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	FreeBSD Phabricator reviews based on git commits

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
PLIST_FILES=	bin/${PORTNAME} \
		man/man1/${PORTNAME}.1.gz

_REV=		964035c409b1b7229c7bc0220e7455e4a038ed4b

post-patch:
	@${MV} ${WRKSRC}/${PORTNAME}.sh?id=* ${WRKSRC}/${PORTNAME}.sh
	@${MV} ${WRKSRC}/${PORTNAME}.1?id=* ${WRKSRC}/${PORTNAME}.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

.include <bsd.port.mk>

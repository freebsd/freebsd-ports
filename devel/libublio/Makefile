# Created by: alepulver
# $FreeBSD$

PORTNAME=	libublio
PORTVERSION=	20070103
CATEGORIES=	devel
MASTER_SITES=	LOCAL/mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	User space caching library

USE_LDCONFIG=	yes

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFLIB="@comment "
.else
PLIST_SUB+=	PROFLIB=""
.endif

USES=		uidfix

SRCCONF=	/dev/null
MAKE_ENV+=	SRCCONF=${SRCCONF}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

# this pre-install is only for debugging pointyhat failures
pre-install:
	@${ECHO_CMD} "===> Environment:"
	@${SETENV} | ${SETENV} LC_ALL=C ${SORT} -f
	@${ECHO_CMD} "===> Makefiles used:"
	@${ECHO_CMD} ${.MAKEFILE_LIST}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>

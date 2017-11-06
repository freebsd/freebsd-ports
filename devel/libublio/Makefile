# Created by: alepulver
# $FreeBSD$

PORTNAME=	libublio
PORTVERSION=	20070103
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	LOCAL/mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	User space caching library

LICENSE=	BSD2CLAUSE

USE_LDCONFIG=	yes

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFLIB="@comment "
.else
PLIST_SUB+=	PROFLIB=""
.endif

USES=		uidfix

SRCCONF=	/dev/null
MAKE_ENV+=	SRCCONF=${SRCCONF}

SUB_FILES=	libublio.pc
SUB_LIST=	PREFIX=${PREFIX} PORTVERSION=${PORTVERSION}

OPTIONS_DEFINE=	DOCS

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

# this pre-install is only for debugging pointyhat failures
pre-install:
	@${ECHO_CMD} "===> Environment:"
	@${SETENV} | ${SORT} -f
	@${ECHO_CMD} "===> Makefiles used:"
	@${ECHO_CMD} ${.MAKEFILE_LIST}

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKDIR}/libublio.pc ${STAGEDIR}${PREFIX}/libdata/pkgconfig/

.include <bsd.port.mk>

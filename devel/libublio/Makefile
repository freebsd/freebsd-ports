# Created by: alepulver
# $FreeBSD$

PORTNAME=	libublio
PORTVERSION=	20070103
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mandree

MAINTAINER=	mandree@FreeBSD.org
COMMENT=	User space caching library

USE_LDCONFIG=	yes

.if defined(NO_PROFILE) || defined(NOPROFILE) || defined(WITHOUT_PROFILE)
PLIST_SUB+=	PROFLIB="@comment "
.else
PLIST_SUB+=	PROFLIB=""
.endif

SRCCONF=	/dev/null
MAKE_ENV+=	SRCCONF=${SRCCONF}

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

# this pre-install is only for debugging pointyhat failures
pre-install:
	@${ECHO_CMD} "===> Environment:"
	@${SETENV} | ${SETENV} LC_ALL=C ${SORT} -f
	@${ECHO_CMD} "===> Makefiles used:"
	@${ECHO_CMD} ${.MAKEFILE_LIST}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

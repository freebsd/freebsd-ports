# New ports collection makefile for:	ARJ archiver
# Date created:			9 April 2002
# Whom:				Konstantin Reznichenko <kot@premierbank.dp.ua>
#
# $FreeBSD$
#

PORTNAME=	arj
PORTVERSION=	3.10g
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	kot@premierbank.dp.ua
COMMENT=	Open-source ARJ

WRKSRC=		${WRKDIR}/${PORTNAME}
USE_REINPLACE=	yes
USE_AUTOCONF_VER=	253
USE_GMAKE=	yes
CONFIGURE_WRKSRC=	${WRKSRC}/gnu
MAKEFILE=	GNUmakefile
STRIP=
LANGUAGE?=	en
MAKE_ENV+=	"LOCALE=${LANGUAGE}"
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS=	%%PREFIX%%/lib/arj

MAN1=		arj-register.1 arj.1 arjdisp.1 rearj.1

post-extract:
	@${REINPLACE_CMD} -e 's!/etc!${LOCALBASE}/etc!' \
		 ${WRKSRC}/arj.c ${WRKSRC}/file_reg.c ${WRKSRC}/rearj.c
	@${REINPLACE_CMD} -e 's!-O2!!' ${WRKSRC}/gnu/configure.in

pre-build:
	@(cd ${BUILD_WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} prepare)

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/doc && ${INSTALL_DATA} COPYING debug.txt ${DOCSDIR}
	cd ${WRKSRC}/resource/en && \
		${INSTALL_DATA} arjl.txt arjs.txt history.txt readme.txt unix.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>

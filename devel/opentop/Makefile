# New ports collection makefile for:	opentop
# Date created:				17 November 2003
# Whom:					Sergey Matveychuk <sem@ciam.ru>
#
# $FreeBSD$
#

PORTNAME=	opentop
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	open-top
DISTNAME=	${PORTNAME}-${PORTVERSION:C|\.|-|g}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${DOCDIST}${EXTRACT_SUFX}

MAINTAINER=	sem@ciam.ru
COMMENT=	A cross-platform C++ framework library

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

DOCDIST=	${PORTNAME}-api-${PORTVERSION:C|\.[0-9]$||:C|\.|-|g}

WCHAR=	"@comment "
STATIC=	"@comment "
DEBUG=	"@comment "

ALL_TARGET=	release_multi_char_shared

.if defined(WITH_WCHAR)
ALL_TARGET+=	release_multi_wchar_shared
WCHAR=	""
.endif
.if defined(WITH_DEBUG)
ALL_TARGET+=	debug_multi_char_shared
.if defined(WITH_WCHAR)
ALL_TARGET+=	debug_multi_wchar_shared
.endif
DEBUG=	""
.endif

PLIST_SUB+=	WCHAR=${WCHAR} DEBUG=${DEBUG}

post-patch:
	@${REINPLACE_CMD} "s/-O3/${CFLAGS}/" \
		${WRKSRC}/buildtools/cxx_compiler_options \
		${WRKSRC}/buildtools/gcc_compiler_options

do-install:
	${MKDIR} ${PREFIX}/include/${PORTNAME}
	cd ${WRKSRC}; ${FIND} ot -name *.h -print | ${TAR} cTf - - | \
			${TAR} xUCf ${PREFIX}/include/${PORTNAME} -
	${INSTALL_PROGRAM} ${WRKSRC}/lib/*.so ${PREFIX}/lib

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/${DOCDIST}/html; ${TAR} cf - . | ${TAR} xUCf ${DOCSDIR} -
.endif

.include <bsd.port.mk>

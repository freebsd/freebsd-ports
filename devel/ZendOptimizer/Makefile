# New ports collection makefile for:	ZendOptimizer
# Date created:			Thu Apr 24 00:23:22 CET 2003
# Whom:				Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	ZendOptimizer
PORTVERSION=	2.1.0b
CATEGORIES=	devel
DISTNAME=	${PORTNAME}-${PORTVERSION}-FreeBSD4.0-i386

MAINTAINER=	sysadmin@alexdupre.com
COMMENT=	An optimizer for PHP code

RUN_DEPENDS=	${LOCALBASE}/bin/php:${PORTSDIR}/www/mod_php4

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

RESTRICTED=	"Redistribution of pre-compiled binaries is not permitted"
NO_CDROM=	"Redistribution of pre-compiled binaries is not permitted"

EXT_DIR=	20020429
PLIST_SUB=	EXT_DIR=${EXT_DIR}

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

# Check for FreeBSD version
.if ${OSVERSION} < 400000 || ${OSVERSION} > 499999
BROKEN=         "This port is for FreeBSD 4 only."
.endif

# Check for ZendOptimizer sources
.if !exists(${DISTDIR}/${DISTNAME}${EXTRACT_SUFX}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE= :\n\
Because of licensing restrictions, you must fetch the source distribution\n\
manually.\n\
Please access http://www.zend.com/store/getfreefile.php?pid=13&zbid=547\n\
with a web browser, read the license and click the \"I ACCEPT\" button.\n\
Download the source file, ${DISTFILES},\n\
and place it in ${DISTDIR}.\n
.endif

do-install:
	@${MKDIR} ${PREFIX}/lib/php/${EXT_DIR}
	${INSTALL_DATA} ${WRKSRC}/data/4_3_x_comp/ZendOptimizer.so \
		${PREFIX}/lib/php/${EXT_DIR}/ZendOptimizer.so
	${INSTALL_DATA} ${WRKSRC}/data/4_3_x_comp/TS/ZendOptimizer.so \
		${PREFIX}/lib/php/${EXT_DIR}/ZendOptimizer_TS.so
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/data/doc/* ${DOCSDIR}
.endif

post-install:
	@${SED} "s|%%LOCALBASE%%|${LOCALBASE}|g;s|%%PREFIX%%|${PREFIX}|g;s|%%EXT_DIR%%|${EXT_DIR}|g" \
		${.CURDIR}/pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>

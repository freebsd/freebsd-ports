# New ports collection makefile for:	root-doc
# Date created:		23 Apr 2004
# Whom:			Radim Kolar
#
# $FreeBSD$
#

PORTNAME=	root-doc
PORTVERSION=	5.02
CATEGORIES=	devel science math
MASTER_SITES=	ftp://root.cern.ch/root/
DISTNAME=	html${PORTVERSION:S/.//}

MAINTAINER=	simon@lang-clan.de
COMMENT=	HTML Documentation for Root framework

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/htmldoc
PLIST=		${WRKDIR}/pkg-plist
IGNOREFILES=	${DISTFILES}

.ifdef NOPORTDOCS
IGNORE=		This package contains only documentation
.endif

pre-install:
	cd ${WRKSRC} && ${FIND} . \( -type f -or -type l \) -exec ${ECHO_CMD} "%%DOCSDIR%%/{}" \; > ${PLIST}
	cd ${WRKSRC} && ${FIND} -d . -mindepth 1 -type d -exec ${ECHO_CMD} "@dirrm %%DOCSDIR%%/{}" \; >> ${PLIST}
	${ECHO_CMD} "@dirrm %%DOCSDIR%%" >> ${PLIST}

do-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${FIND} . | ${CPIO} -pdm -R ${SHAREOWN}:${SHAREGRP} ${DOCSDIR}

.include <bsd.port.mk>

# New ports collection makefile for:	fretsonfire-data
# Date created:		2006-10-02
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	data
PORTVERSION=	1.0.225
CATEGORIES=	games python
MASTER_SITES=	http://louhi.kempele.fi/~skyostil/uv/fretsonfire/dist/
PKGNAMEPREFIX=	fretsonfire-
DISTNAME=	${PKGNAMEPREFIX:S/f/F/g:S/o/O/}${PORTVERSION:S/$/-linux/}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Frets on Fire data files

NO_BUILD=	yes
DATADIR=	share/${PKGNAMEPREFIX:S/-//}
RESTRICTED=	Only Unreal Voodoo site is allowed to distribute the music
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX:S/f/F/g:S/o/O/:S/-//}

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - ${PKGNAMEPREFIX:S/f/F/g:S/o/O/:S/-//}/${PORTNAME}

do-install:
	@${MKDIR} ${PREFIX}/${DATADIR}
	@cd ${WRKSRC}/data && \
		${FIND} * -type d -exec ${MKDIR} "${PREFIX}/${DATADIR}/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${PREFIX}/${DATADIR}/{}" \;

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>

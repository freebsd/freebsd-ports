# Created by: Jose Alonso Cardenas Marquez <acm@FreeBSD.org>

PORTNAME=	data
PORTVERSION=	1.3.110
CATEGORIES=	games python
MASTER_SITES=	SF/fretsonfire/fretsonfire/${PORTVERSION}
PKGNAMEPREFIX=	fretsonfire-
DISTNAME=	${PKGNAMEPREFIX:S/f/F/g:S/o/O/}${PORTVERSION}
DIST_SUBDIR=	${PKGNAMEPREFIX:S/-//}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Frets on Fire data files

# Converted from RESTRICTED
LICENSE=	fretsonfire
LICENSE_NAME=	fretsonfire
LICENSE_TEXT=	Only Unreal Voodoo site is allowed to distribute the music
LICENSE_PERMS=	auto-accept

NO_BUILD=	yes
NO_ARCH=	yes
DATADIR=	${PREFIX}/share/${PKGNAMEPREFIX:S/-//}
WRKSRC=		${WRKDIR}/Frets\ on\ Fire-${PORTVERSION}

EXTRACT_AFTER_ARGS=	--exclude 'win32' "Frets on Fire-${PORTVERSION}/${PORTNAME}"

do-install:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>

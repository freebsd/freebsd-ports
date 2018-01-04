# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvs-syncmail
PORTVERSION=	2.1
CATEGORIES=	devel python
MASTER_SITES=	SF
DISTNAME=	syncmail
EXTRACT_SUFX=	# none

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS notification tool

LICENSE=	BSD3CLAUSE  # see CVS repository on SourceForge

RUN_DEPENDS=	cvs:devel/cvs

USES=		python shebangfix
SHEBANG_FILES=	${DISTNAME}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>

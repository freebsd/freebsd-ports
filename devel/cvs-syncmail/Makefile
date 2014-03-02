# Created by: Greg Larkin <glarkin@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cvs-syncmail
PORTVERSION=	2.1
CATEGORIES=	devel python
MASTER_SITES=	SF
DISTNAME=	syncmail
EXTRACT_SUFX=

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CVS notification tool

USES=		shebangfix
SHEBANG_FILES=	${DISTNAME}
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON=	yes

PLIST_FILES=	bin/${DISTNAME}

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD && ${OPSYS} > 1000000
RUN_DEPENDS=	cvs:${PORTSDIR}/devel/cvs
.endif

do-extract:
	@${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${DISTNAME}

.include <bsd.port.post.mk>

# New ports collection makefile for:	cvs-syncmail
# Date created:				13 August 2007
# Whom:					Greg Larkin <glarkin@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cvs-syncmail
PORTVERSION=	2.1
CATEGORIES=	devel python
MASTER_SITES=	SF
DISTNAME=	syncmail
EXTRACT_SUFX=

MAINTAINER=	glarkin@FreeBSD.org
COMMENT=	CVS notification tool

.if defined(WITH_CVSNT)
# Use the CVSNT binary when generating diffs instead of the system CVS
RUN_DEPENDS=	${LOCALBASE}/bin/cvsnt:${PORTSDIR}/devel/cvsnt
.endif

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_PYTHON=	2.0+

PLIST_FILES=	bin/${DISTNAME}

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}

do-patch:
	@${REINPLACE_CMD} -e "s| /usr/bin/python|${PYTHON_CMD}|" \
		${WRKSRC}/${DISTNAME}

	@${REINPLACE_CMD} -e "s|cvs -fn update|/usr/bin/cvs -fn update|" \
		${WRKSRC}/${DISTNAME}

.if defined(WITH_CVSNT)
	@${REINPLACE_CMD} -e "s|/usr/bin/cvs|${LOCALBASE}/bin/cvsnt|" \
	    ${WRKSRC}/${DISTNAME}
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/${DISTNAME}

.include <bsd.port.mk>

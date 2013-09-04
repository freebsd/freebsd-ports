# New ports collection makefile for:	joe
# Date created:		01 Jul 1995
# Whom:			torstenb@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	joe
PORTVERSION=	2.9.8
CATEGORIES+=	editors
MASTER_SITES=	SF/joe-editor/JOE%20sources/joe-${PORTVERSION}

MAINTAINER?=	toasty@dragondata.com
COMMENT?=	Joe's Own Editor

RUN_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

LATEST_LINK?=	joe2
CONFLICTS=	joe-3*

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		iconv
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${ICONV_LIB}"
CPPFLAGS+=	-I${LOCALBASE}/include

ALL_TARGET=	${PORTNAME}
MAN1=		${PORTNAME}.1

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${WRKSRC}/README.cvs ${WRKSRC}/ChangeLog\
		 ${WRKSRC}/INFO ${WRKSRC}/NEWS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LIST ${DOCSDIR}/CommandList
.endif

.include <bsd.port.mk>

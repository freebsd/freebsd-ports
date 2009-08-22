# New ports collection makefile for:	fte
# Date created:				8 May 2000
# Whom:					gelf
#
# $FreeBSD$
#

PORTNAME=		fte
PORTVERSION=		20051115
PORTREVISION=	2
CATEGORIES=		editors
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=		${PORTNAME}-${PORTVERSION:S/./b/}-src.zip \
			${PORTNAME}-${PORTVERSION:S/./b/}-common.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=		acm@FreeBSD.org
COMMENT=		A full-featured text editor for X11

WRKSRC=			${WRKDIR}/fte

USE_XORG=	x11 xpm
USE_ZIP=		yes
USE_PERL5_BUILD=	yes

post-patch:
	@${REINPLACE_CMD} -e 's,^PREFIX=,PREFIX?=,' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC}/doc && \
		${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${DOCSDIR}/{}" \;
.endif

.include <bsd.port.mk>

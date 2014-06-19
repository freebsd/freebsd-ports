# Created by: gelf
# $FreeBSD$

PORTNAME=		fte
PORTVERSION=		20051115
PORTREVISION=	2
CATEGORIES=		editors
MASTER_SITES=		SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTFILES=		${PORTNAME}-${PORTVERSION:S/./b/}-src.zip \
			${PORTNAME}-${PORTVERSION:S/./b/}-common.zip
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=		acm@FreeBSD.org
COMMENT=	Full-featured text editor for X11

WRKSRC=			${WRKDIR}/fte

USE_XORG=	x11 xpm
USES=		perl5 zip
USE_PERL5=	build

NO_STAGE=	yes
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

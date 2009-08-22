# New ports collection makefile for:    ko-scim-tables
# Date created:		22 May 2004
# Whom:			Jie Gao	<gaoj@cpsc.ucalgary.ca>
#
# $FreeBSD$
#    $MCom: ports/korean/scim-tables/Makefile,v 1.1 2006/09/30 03:44:11 ahze Exp $

PORTNAME=	scim-tables
PORTVERSION=	0.5.7
PORTREVISION=	3
CATEGORIES=	korean
MASTER_SITES=	SF/scim/${PORTNAME}/${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	SCIM table based Korean input methods

BUILD_DEPENDS=	scim-make-table:${PORTSDIR}/textproc/scim-table-imengine
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

post-install:
	@${CAT} ${PKGMESSAGE}
	@${ECHO}
	@${ECHO} To display this message again, type \`pkg_info -D ${PKGNAME}\'
	@${ECHO}

.include <bsd.port.post.mk>

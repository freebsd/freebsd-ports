# New ports collection makefile for:	gqview
# Date Created:				27 Oct 1998
# Whom:					Vanilla Pooh Shu <vanilla@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gqview
PORTVERSION=	1.4.0
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ale@FreeBSD.org
COMMENT=	Another gtk2-based graphic file viewer

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_X_PREFIX=	yes
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib"

CONFLICTS=	gqview-devel-1.3.*

MAN1=		gqview.1

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>

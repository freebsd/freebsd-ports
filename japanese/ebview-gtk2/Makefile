# New ports collection makefile for:	ebview-gtk2
# Date Created:				7 Dec 2003
# Whom:					<faust@ua.airnet.ne.jp>
#
# $FreeBSD$
#

PORTNAME=	ebview
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	japanese
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMESUFFIX=	-gtk2

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Electronic Book Viewer

LIB_DEPENDS=	eb.7:${PORTSDIR}/japanese/eb

CONFLICTS=	ja-ebview-0*

USE_GNOME=	gtk20 gnometarget
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e \
		's|-pthread|${PTHREAD_LIBS:S/"//g}|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/GTK_DISABLE_DEPRECATED/d' ${WRKSRC}/src/defs.h

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

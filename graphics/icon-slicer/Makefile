# New ports collection makefile for:	icon-slicer
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon-slicer
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.freedesktop.org/software/icon-slicer/releases/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An utility for generating icon and cursor themes

LIB_DEPENDS=	popt:${PORTSDIR}/devel/popt

USE_GNOME=	gtk20
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/icon-slicer

.if !defined(NOPORTDOCS)
PORTDOCS=	*
.endif

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS/ s|examples||' ${WRKSRC}/Makefile.in

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS README TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

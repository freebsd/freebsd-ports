# New ports collection makefile for:	nogger
# Date created:				2002-10-27
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	nogger
PORTVERSION=	0.8.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://www.efd.lth.se/~d00jkr/nogger/

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	No-frills, GTK-based Ogg Vorbis player

LIB_DEPENDS=	gtk-x11-2.0.200:${PORTSDIR}/x11-toolkits/gtk20 \
		vorbis.3:${PORTSDIR}/audio/libvorbis

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 500113
BROKEN=	"just makes a humming noise"
.endif

PLIST_FILES=	bin/nogger
.ifndef(NOPORTDOCS)
.for ii in COPYING README Thanks
PLIST_FILES+=	share/doc/nogger/${ii}
.endfor
PLIST_DIRS=	share/doc/nogger
.endif
USE_GMAKE=	y
ALL_TARGET=	nogger

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nogger ${PREFIX}/bin
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for ii in COPYING README Thanks
	${INSTALL_DATA} ${WRKSRC}/${ii} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

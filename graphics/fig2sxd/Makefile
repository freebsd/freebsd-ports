# New ports collection makefile for:	fig2sxd
# Date created:				6 Sep 2005
# Whom:					Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	fig2sxd
PORTVERSION=	0.20
CATEGORIES=	graphics converters
MASTER_SITES=	CRITICAL
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert .xfig files to the OpenOffice draw format

USE_GMAKE=	yes
MAKE_JOBS_SAFE=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAN1=		fig2sxd.1
PLIST_FILES=	bin/fig2sxd

post-patch:
	@${REINPLACE_CMD} -e \
		'/^CXX/d; s|^\(all:\).*|\1 $$(TARGET1) fig2sxd.1|' \
			${WRKSRC}/${MAKEFILE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MANPREFIX}/man/man1

.include <bsd.port.mk>

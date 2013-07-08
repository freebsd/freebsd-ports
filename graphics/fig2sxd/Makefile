# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	fig2sxd
PORTVERSION=	0.21
CATEGORIES=	graphics converters
MASTER_SITES=	CRITICAL SF
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Convert .xfig files to the OpenOffice draw format

USES=		gmake
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

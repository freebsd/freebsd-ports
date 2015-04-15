# $FreeBSD$

PORTNAME=	helpviewer
PORTVERSION=	0.3
PORTREVISION=	4
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://www.roard.com/helpviewer/download/
DISTNAME=	HelpViewer-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online help viewer for GNUstep programs

LICENSE=	GPLv2

USES=		gnustep
USE_GNUSTEP=	back build

FIXME=	HandlerStructureXLP.h TextFormatterXLP.h

post-patch:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|Foundation/GSXML.h|GNUstepBase/GSXML.h|' \
		${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>

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

USE_GNUSTEP=	yes
USE_GNUSTEP_BACK=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes

FIXME=	HandlerStructureXLP.h TextFormatterXLP.h

post-patch:
.for i in ${FIXME}
	${REINPLACE_CMD} -e 's|Foundation/GSXML.h|GNUstepBase/GSXML.h|' \
		${WRKSRC}/${i}
.endfor

.include <bsd.port.mk>

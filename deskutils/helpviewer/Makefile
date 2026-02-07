PORTNAME=	helpviewer
PORTVERSION=	0.3
PORTREVISION=	13
CATEGORIES=	deskutils gnustep
MASTER_SITES=	http://www.roard.com/helpviewer/download/
DISTNAME=	HelpViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Online help viewer for GNUstep programs
WWW=		http://www.roard.com/helpviewer/

LICENSE=	GPLv2

USES=		gnustep tar:tgz
USE_GNUSTEP=	back build

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
ADDITIONAL_CPPFLAGS+=	-Wno-error=int-conversion
.endif

post-patch:
	${REINPLACE_CMD} -e 's|Foundation/GSXML.h|GNUstepBase/GSXML.h|' \
		${WRKSRC}/HandlerStructureXLP.h \
		${WRKSRC}/TextFormatterXLP.h

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/GNUstep/System/Applications/HelpViewer.app/HelpViewer

.include <bsd.port.mk>

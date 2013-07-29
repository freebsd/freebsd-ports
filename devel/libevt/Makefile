# Created by: Antoine Brodin <antoine@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libevt
DISTVERSION=	alpha-20130726
CATEGORIES=	devel
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSYm01VnUtLXNUZ2M/ \
		LOCAL/antoine

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Library and tooling to access the Windows Event Log (EVT) format

LICENSE=	LGPL3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-python
USES=		gettext iconv pathfix
USE_PYTHON=	-2.7
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION:E}

MAN1=		evtexport.1 evtinfo.1
MAN3=		libevt.3

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	AUTHORS ChangeLog
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/${PORTNAME}/* \
		${WRKSRC}/examples/${PORTNAME:S,lib,py,}/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>

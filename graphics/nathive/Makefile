# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nathive
PORTVERSION=	0.924
CATEGORIES=	graphics
MASTER_SITES=	http://www.nathive.org/dl/ \
		http://mirror.amdmi3.ru/distfiles/
EXTRACT_SUFX=	.tgz

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image editor

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2

USES=		gmake
USE_PYTHON=	2
MAKEFILE=	makefile
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} share/applications/nathive.desktop
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/BASE =/ s|=.*|= ${PREFIX}/|; \
		s|python |${PYTHON_CMD} |' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|/usr/share/nathive|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}.desktop

post-build:
	${STRIP_CMD} ${WRKSRC}/nathive/libc/*.so

.include <bsd.port.mk>

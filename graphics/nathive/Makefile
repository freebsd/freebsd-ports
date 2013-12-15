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

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e '/BASE =/ s|=.*|= ${PREFIX}/|; \
		s|cp -r \([^ ]*\)/|cp -R \1|; \
		s|python |${PYTHON_CMD} |' ${WRKSRC}/${MAKEFILE}
	@${REINPLACE_CMD} -e 's|/usr/share/nathive|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}.desktop
.if ! ${PORT_OPTIONS:MDOCS}
	@${REINPLACE_CMD} -e '/install.*DOC/ d; /mkdir -p.*BASE.*DOC/ d' \
		${WRKSRC}/${MAKEFILE}
.endif

.include <bsd.port.mk>

# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nathive
PORTVERSION=	0.924
CATEGORIES=	graphics
MASTER_SITES=	http://www.nathive.org/dl/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Lightweight image editor

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake gnome python:2.7 shebangfix tar:tgz
SHEBANG_GLOB=	*.py *.cy
USE_GNOME=	pygtk2
MAKEFILE=	makefile
ALL_TARGET=	default

WRKSRC=		${WRKDIR}/${PORTNAME}

PLIST_FILES=	bin/${PORTNAME} \
		share/applications/nathive.desktop
PORTDATA=	*
PORTDOCS=	*
PLIST_DIRS=	%%DATADIR%%/cfg/presets/select \
		%%DATADIR%%/cfg/presets/picker \
		%%DATADIR%%/cfg/presets/eraser \
		%%DATADIR%%/cfg/presets/crop \
		%%DATADIR%%/cfg/presets/brush \
		%%DATADIR%%/cfg/console

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/BASE =/ s|=.*|= ${PREFIX}/|; \
		s|python |${PYTHON_CMD} |' \
		${WRKSRC}/${MAKEFILE}
.for util in shdata makeplugs.py indenter.py docgen/docfile.py cybuild.py extbuild.py
	@${REINPLACE_CMD} -e 's|python |${PYTHON_CMD} |' \
		${WRKSRC}/utils/${util}
.endfor
	@${REINPLACE_CMD} -e 's|/usr/share/nathive|${DATADIR}|' \
		${WRKSRC}/${PORTNAME}.desktop

post-build:
	@${STRIP_CMD} ${WRKSRC}/nathive/libc/*.so

.include <bsd.port.mk>

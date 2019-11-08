# Created by: Remington Lang <MrL0Lz@gmail.com>
# $FreeBSD$

PORTNAME=	everygui
PORTVERSION=	0.99.b
PORTREVISION=	9
CATEGORIES=	deskutils gnome
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Dynamic GUI for an OS command

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		dos2unix gnome python:2.7 shebangfix
SHEBANG_FILES=	src/*.py
DOS2UNIX_GLOB=	*.py
USE_PYTHON=	distutils autoplist
USE_GNOME=	libglade2 pygnome2
NO_ARCH=	yes

WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${FIND} ${WRKSRC} -name "*.py" | ${XARGS} ${REINPLACE_CMD} -e\
		's,/usr/share,${PREFIX}/share,g' -e\
		's,/usr/src,${PREFIX}/src,g'
	@${REINPLACE_CMD} -e 's,/usr/src/everygui,${PREFIX}/src/everygui,g' \
		${WRKSRC}/everygui
	@${REINPLACE_CMD} -e 's,/usr/src,${PREFIX}/src,g' \
		${WRKSRC}/egdesign
	@${FIND} ${WRKSRC} -name "*.bak" -delete

.include <bsd.port.mk>

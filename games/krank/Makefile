# $FreeBSD$

PORTNAME=	krank
PORTVERSION=	07
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTVERSION}

MAINTAINER=	nemysis@gmx.ch
COMMENT=	A little casual game

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}game>=0:${PORTSDIR}/devel/py-game \
		${PYNUMPY}

USE_BZIP2=	yes
USE_PYTHON=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.png

PORTDATA=	*
PORTDOCS=	CHANGELOG.txt README

post-patch:
	${REINPLACE_CMD} -e 's|`dirname.*|${DATADIR}|' ${WRKSRC}/${PORTNAME}

.include <bsd.port.options.mk>

do-install:
# Scripts
	${INSTALL_SCRIPT} ${WRKSRC}/krank ${PREFIX}/bin

# Data
	${MKDIR} ${DATADIR}
.  for d in art fonts html levels sounds src
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${DATADIR})
.  endfor
	${INSTALL_DATA} ${WRKSRC}/krank.iss ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/logo.xcf ${DATADIR}

# Pixmaps
	${INSTALL_DATA} ${WRKSRC}/html/gfx/logo.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

# Documentation
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.  for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.  endfor
.endif

.include <bsd.port.mk>

# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	impressive
PORTVERSION=	0.10.3
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/Impressive/${PORTVERSION}/
DISTNAME=	Impressive-${PORTVERSION}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	The stylish way of giving presentations

LICENSE=	GPLv2

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}opengl>=0:${PORTSDIR}/graphics/py-opengl \
		${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging \
		xpdf:${PORTSDIR}/graphics/xpdf \
		pdftk:${PORTSDIR}/print/pdftk \
		xdg-open:${PORTSDIR}/devel/xdg-utils \
		mplayer:${PORTSDIR}/multimedia/mplayer \
		${PYGAME}

USE_PYTHON=	yes
USE_GHOSTSCRIPT_RUN=	yes
NO_BUILD=	yes
PLIST_FILES=	bin/${PORTNAME}

MAN1=		${PORTNAME}.1

PORTDOCS=	${PORTNAME}.html demo.pdf

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PREFIX}/bin/${PORTNAME}
	@${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>

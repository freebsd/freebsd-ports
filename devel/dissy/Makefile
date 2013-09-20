# Created by: Sofian Brabez <sbrabez@gmail.com>
# $FreeBSD$

PORTNAME=	dissy
PORTVERSION=	10
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Graphical frontend to the objdump disassembler

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/gtk-2.0/gtk/__init__.py:${PORTSDIR}/x11-toolkits/py-gtk2 \
		${PYTHON_SITELIBDIR}/webkit/__init__.py:${PORTSDIR}/www/py-webkitgtk
LIB_DEPENDS=	rsvg-2.2:${PORTSDIR}/graphics/librsvg2

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.if !defined(NO_INSTALL_MANPAGES)
MAN1=	${PORTNAME}.1
MANCOMPRESSED=	no
.endif

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

PORTDOCS=	COPYING ChangeLog README UPGRADE

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if !defined(NO_INSTALL_MANPAGES)
	${INSTALL_MAN} ${MAN1:S,^,${WRKSRC}/,} ${MAN1PREFIX}/man/man1
.endif

.include <bsd.port.mk>

# New ports collection makefile for:	comix
# Date created:				26 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	comix
PORTVERSION=	2.7
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A GTK2 comic book viewer for .cbz, .cbr and .cbt files

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

NO_BUILD=	yes
USE_GNOME=	desktopfileutils pygtk2
USE_PYTHON=	yes
USE_X_PREFIX=	yes
USE_REINPLACE=	yes

DOCS=		COPYING ChangeLog README
MAN1=		comix.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/${PORTNAME}.1.gz

post-patch:
	@${REINPLACE_CMD} -e 's|share/man|man|g ; s|1.gz|1|g' \
		${WRKSRC}/install.py

do-install:
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install --installdir ${PREFIX})
	@${MKDIR} ${PREFIX}/share/mime/packages/
	@${INSTALL_DATA} ${WRKSRC}/mime/${PORTNAME}.xml \
		${PREFIX}/share/mime/packages/

post-install:
	@-update-desktop-database
	@-update-mime-database ${PREFIX}/share/mime
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>

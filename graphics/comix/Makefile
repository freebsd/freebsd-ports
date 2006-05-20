# New ports collection makefile for:	comix
# Date created:				26 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	comix
PORTVERSION=	3.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A GTK2 comic book viewer for .cbz, .cbr and .cbt files

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging

NO_BUILD=	yes
USE_GNOME=	desktopfileutils pygtk2
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
USE_X_PREFIX=	yes
INSTALLS_ICONS=	yes

DOCS=		COPYING ChangeLog README
MAN1=		comix.1 comicthumb.1

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mnautilus2}!="" || defined(WITH_THUMBNAILS)) && !defined(WITHOUT_THUMBNAILS)
USE_GNOME+=	gconf2
#MAN1+=		comicthumb.1
GCONF_SCHEMAS=	comicbook.schemas
PLIST_SUB+=	THUMBNAILS:=""
THUMBNAILS_ENABLED=yes
.else
PLIST_SUB+=	THUMBNAILS:="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name \*.gz | ${XARGS} ${GUNZIP_CMD}

post-patch:
	@${REINPLACE_CMD} -e "s|share/man|man|g ; s|1.gz|1|g ; \
		s|/usr/share/mime|${PREFIX}/share/mime|g ; \
		s|'/usr'|'${PREFIX}'|g" \
			${WRKSRC}/install.py

do-install:
.if defined(THUMBNAILS_ENABLED)
	@${MKDIR} ${PREFIX}/share/mime/packages
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install --installdir ${PREFIX})
	@${MKDIR} ${PREFIX}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/mime/comicbook.schemas \
		${PREFIX}/etc/gconf/schemas/
.else
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install \
			--installdir ${PREFIX} --no-mime)
.endif

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

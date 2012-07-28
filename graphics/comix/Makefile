# New ports collection makefile for:	comix
# Date created:				26 November 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports-stable/graphics/comix/Makefile,v 1.1 2006/10/21 18:39:46 mezz Exp $
#

PORTNAME=	comix
PORTVERSION=	4.0.4
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK2 comic book viewer for .cbz, .cbr, and .cbt files

RUN_DEPENDS=	unrar:${PORTSDIR}/archivers/unrar \
		${PYTHON_SITELIBDIR}/PIL/__init__.py:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_SITELIBDIR}/_sqlite3.so:${PORTSDIR}/databases/py-sqlite3

NO_BUILD=	yes
USE_GNOME=	desktopfileutils pygtk2
WANT_GNOME=	yes
USE_PYTHON=	yes
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes

DOCS=		COPYING ChangeLog README
MAN1=		comix.1

.include <bsd.port.pre.mk>

.if (${HAVE_GNOME:Mnautilus2}!="" || defined(WITH_THUMBNAILS)) && !defined(WITHOUT_THUMBNAILS)
USE_GNOME+=	gnomehier gconf2
MAN1+=		comicthumb.1
GCONF_SCHEMAS=	comicbook.schemas
PLIST_SUB+=	THUMBNAILS:=""
THUMBNAILS_ENABLED=yes
.else
PLIST_SUB+=	THUMBNAILS:="@comment "
.endif

post-extract:
	@${FIND} ${WRKSRC} -name \*.gz | ${XARGS} ${GUNZIP_CMD}
	@${RM} -f ${WRKSRC}/src/*.pyc

post-patch:
	@${REINPLACE_CMD} -e "s|share/man|man|g ; s|1.gz|1|g ; \
		s|%%GCONF_CONFIG_SOURCE%%|${GCONF_CONFIG_SOURCE}|g" \
			${WRKSRC}/install.py
	@${REINPLACE_CMD} -e "s|\[base,.*\]:|\[base, '/usr/local'\]:|g" \
		${WRKSRC}/src/about.py ${WRKSRC}/src/icons.py

do-install:
.if defined(THUMBNAILS_ENABLED)
	@${MKDIR} ${PREFIX}/share/mime/packages
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install --dir ${PREFIX})
	@${MKDIR} ${PREFIX}/etc/gconf/schemas
	@${INSTALL_DATA} ${WRKSRC}/mime/comicbook.schemas \
		${PREFIX}/etc/gconf/schemas/
.else
	@(cd ${WRKSRC} ; \
		${PYTHON_CMD} install.py install \
			--dir ${PREFIX} --no-mime)
.endif

post-install:
	@-update-desktop-database
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${DATADIR}/src

.include <bsd.port.post.mk>

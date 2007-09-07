# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/devel/anjuta-devel/Makefile,v 1.14 2006/09/10 00:51:07 mezz Exp $
#

PORTNAME=	anjuta
PORTVERSION=	2.2.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

BUILD_DEPENDS=	autogen:${PORTSDIR}/devel/autogen \
		bash:${PORTSDIR}/shells/bash \
		neato:${PORTSDIR}/graphics/graphviz
LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre \
		gbf-1.1:${PORTSDIR}/devel/gnome-build \
		gladeui-1.5:${PORTSDIR}/devel/glade3 \
		devhelp-1.0:${PORTSDIR}/devel/devhelp
RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		autogen:${PORTSDIR}/devel/autogen \
		neato:${PORTSDIR}/graphics/graphviz \
		libtool:${PORTSDIR}/devel/libtool15 \
		${LOCALBASE}/libdata/pkgconfig/gnome-icon-theme.pc:${PORTSDIR}/misc/gnome-icon-theme

USE_BZIP2=	yes
USE_XLIB=	yes
USE_AUTOTOOLS=	autotools:run
USE_GMAKE=	yes
USE_GETTEXT=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui libgnomeui vte \
		gtksourceview
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_LDCONFIG=	yes

MAN1=		anjuta.1 anjuta_launcher.1

OPTIONS=	SVN "Build subversion plugins" off

.include <bsd.port.pre.mk>

.if defined(WITH_SVN)
BUILD_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	svn:${PORTSDIR}/devel/subversion
USE_APACHE=	2.0+

CONFIGURE_ARGS+=--with-subversion-dir=${LOCALBASE}/bin \
		--with-svn-include=${LOCALBASE}/include \
		--with-svn-lib=${LOCALBASE}/lib \
		--with-apr-config=${LOCALBASE}/bin/apr-1-config \
		--with-apu-config=${LOCALBASE}/bin/apu-1-config
PLIST_SUB+=	SVN=""
.else
CONFIGURE_ARGS+=--disable-plugin-subversion
PLIST_SUB+=	SVN="@comment "
.endif

post-configure:
	@${REINPLACE_CMD} -e 's|/bin/bash|${LOCALBASE}/bin/bash| ; \
	    	s|/usr/local|${PREFIX}| ; \
		s|share/anjuta|share/gnome/anjuta|' \
	    	${WRKSRC}/global-tags/create_global_tags.sh
	@${REINPLACE_CMD} -e 's|PKG_PATH|PKG_CONFIG_PATH|g' \
	    	${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|[(]datadir[)]/icons/gnome|(prefix)/share/icons/gnome|g' \
	    	${WRKSRC}/mime/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.post.mk>

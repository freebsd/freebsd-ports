# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	0.2.8
CATEGORIES=	japanese x11
MASTER_SITES=	http://freedesktop.org/Software/UimDownload/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Input method library

LIB_DEPENDS=	anthy.0:${PORTSDIR}/japanese/anthy

USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
USE_GNOME=	gnometarget glib20
USE_GMAKE=	yes
USE_ICONV=	yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		LDFLAGS="-L${X11BASE}/lib  -L${LOCALBASE}/lib"

DOCSDIR_JA=	${PREFIX}/share/doc/ja/uim
PLIST_SUB+=	DOCSDIR_JA="${DOCSDIR_JA:S,^${PREFIX}/,,}"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mgtk20}
USE_GNOME+=	gtk20
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

.if ${HAVE_GNOME:Mgnomepanel}
USE_GNOME+=	gnomepanel
PLIST_SUB+=	GNOME=""
.else
PLIST_SUB+=	GNOME="@comment "
.endif

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR_JA}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

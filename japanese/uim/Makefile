# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	0.4.2.1
PORTREVISION=	1
CATEGORIES=	japanese x11
MASTER_SITES=	http://freedesktop.org/Software/UimDownload/

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Input method library

LIB_DEPENDS=	anthy.1:${PORTSDIR}/japanese/anthy \
		m17n.1:${PORTSDIR}/devel/m17n-lib

USE_REINPLACE=	yes
USE_X_PREFIX=	yes
USE_PERL5_BUILD=yes
INSTALLS_SHLIB=	yes
WANT_GNOME=	yes
USE_GNOME=	lthack gnometarget glib20
USE_GMAKE=	yes
USE_ICONV=	yes
USE_INC_LIBTOOL_VER=13
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

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' ${WRKSRC}/scm/skk.scm ${WRKSRC}/scm/custom.scm

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR_JA}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.post.mk>

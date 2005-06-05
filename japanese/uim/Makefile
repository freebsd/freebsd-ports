# New ports collection makefile for:   uim
# Date created:        31 August 2003
# Whom:                MANTANI Nobutaka <nobutaka@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uim
PORTVERSION=	0.4.6
PORTREVISION=	3
CATEGORIES=	japanese x11
MASTER_SITES=	http://uim.freedesktop.org/releases/

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

.if exists(${X11BASE}/bin/scim) || defined(WITH_SCIM)
LIB_DEPENDS=	scim-1.0.7:${PORTSDIR}/textproc/scim
PLIST_SUB+=	SCIM=""
.else
PLIST_SUB+=	SCIM="@comment "
.endif

.if exists(${LOCALBASE}/sbin/cannaserver) || defined(WITH_CANNA)
LIB_DEPENDS=	canna.1:${PORTSDIR}/japanese/Canna
CONFIGURE_ARGS+=--with-canna
PLIST_SUB+=	CANNA=""
.else
PLIST_SUB+=	CANNA="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's,/usr,${LOCALBASE},' ${WRKSRC}/scm/skk.scm ${WRKSRC}/scm/custom.scm

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR_JA}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.ja ${DOCSDIR_JA}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.post.mk>

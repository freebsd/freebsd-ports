# New ports collection makefile for:	irc/lostirc
# Date created:				01 Jul 2002
# Whom:					Juan Salaverria <rael@vectorstar.net>
#
# $FreeBSD$
#

PORTNAME=	lostirc
PORTVERSION=	0.2.7
PORTREVISION=	1
CATEGORIES=	irc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	rael@vectorstar.net
COMMENT=	LostIRC is a simple and minimal IRC client for X

LIB_DEPENDS=	gtkmm-2:${PORTSDIR}/x11-toolkits/gtk--2 \
		intl.5:${PORTSDIR}/devel/gettext-old

USE_X_PREFIX=	yes
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib"

MAN1=	lostirc.1

DOCS=	AUTHORS COPYING ChangeLog TODO README INSTALL

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -E "s@^(Gnomedir = ).*@\1${PREFIX}/share/gnome/apps/Internet@" ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E "s@(Gnomedir = ).*@\1${PREFIX}/share/gnome/apps/Internet@" ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -E "s@^(pixmapdir = ).*@\1${PREFIX}/share/gnome/pixmaps@" ${WRKSRC}/Makefile.am
	${REINPLACE_CMD} -E "s@(pixmapdir = ).*@\1${PREFIX}/share/gnome/pixmaps@" ${WRKSRC}/Makefile.in
	${REINPLACE_CMD} -e 's|_nl_domain_bindings|libintl_nl_domain_bindings|' ${WRKSRC}/configure

pre-install:
	${REINPLACE_CMD} -E 's|MKINSTALLDIRS = \$$\(top_builddir\)/|MKINSTALLDIRS = |g' ${WRKSRC}/intl/Makefile
	${REINPLACE_CMD} -E 's|MKINSTALLDIRS = \$$\(top_builddir\)/|MKINSTALLDIRS = |g' ${WRKSRC}/po/Makefile

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>

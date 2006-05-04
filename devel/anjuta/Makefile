# New ports collection makefile for:	anjuta
# Date created:				31 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	anjuta
PORTVERSION=	1.2.4
PORTREVISION=	4
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	anjuta

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Integrated Development Environment for C and C++

LIB_DEPENDS=	pcre.0:${PORTSDIR}/devel/pcre-utf8
RUN_DEPENDS=	${LOCALBASE}/gnu-autotools/bin/autoconf:${PORTSDIR}/devel/gnu-autoconf \
		${LOCALBASE}/gnu-autotools/bin/automake:${PORTSDIR}/devel/gnu-automake \
		${LOCALBASE}/gnu-autotools/bin/libtool:${PORTSDIR}/devel/gnu-libtool

USE_X_PREFIX=	yes
USE_GMAKE=	yes
INSTALLS_OMF=	yes
USE_GNOME=	gnomeprefix gnomehack libgnomeprintui libgnomeui vte
GNU_CONFIGURE=	yes
USE_GCC=	3.4+
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=		anjuta.1 anjuta_launcher.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=	Uses symbols not available on 4.X
.endif

post-configure:
	@${SED} -e 's|%%LOCALBASE%%|${LOCALBASE}|g ; \
		s|%%PREFIX%%|${PREFIX}|g' < ${FILESDIR}/anjuta \
		> ${WRKDIR}/anjuta

post-install:
	${INSTALL_DATA} ${WRKSRC}/pixmaps/applogo.png \
		${PREFIX}/share/gnome/anjuta/glade
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in AUTHORS COPYING ChangeLog FUTURE INSTALL NEWS README \
	doc/ScintillaDoc.html TODO
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	${MV} ${PREFIX}/bin/anjuta ${PREFIX}/bin/anjuta-bin
	${INSTALL_SCRIPT} ${WRKDIR}/anjuta ${PREFIX}/bin

.include <bsd.port.post.mk>

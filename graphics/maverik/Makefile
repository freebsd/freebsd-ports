# ex:ts=8
# New ports collection makefile for:	maverik
# Date created:			Nov 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	maverik
PORTVERSION=	6.2
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	http://aig.cs.man.ac.uk/maverik/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A publicly available virtual reality (VR) system

USE_SUBMAKE=	yes
USE_GL=		yes
WANT_GNOME=	yes
SCRIPTS_ENV=	WRKDIRPREFIX="${WRKDIRPREFIX}" \
		REALCURDIR="${.CURDIR}" \
		DISTNAME="${DISTNAME}"
HAS_CONFIGURE=	yes
CONFIGURE_SCRIPT=	setup
CONFIGURE_ARGS=	--MESAPATH=${X11BASE}
INSTALLS_SHLIB=	yes
MANCOMPRESSED=	no

.include <bsd.port.pre.mk>

.if defined(WITH_PNG)
LIB_DEPENDS+=	png:${PORTSDIR}/graphics/png

CONFIGURE_ARGS+=	--PNGLIBS="-L${LOCALBASE}/lib -lpng" \
			--PNGINCL="-I${LOCALBASE}/include"
.endif

.if ${HAVE_GNOME:Mgtk12}!=""
LIB_DEPENDS+=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea
USE_GNOME+=	gtk12
CONFIGURE_ARGS+=	--GTK
PLIST_SUB+=	GTK=""
.else
PLIST_SUB+=	GTK="@comment "
.endif

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genman3list.sh

post-patch:
	@${REINPLACE_CMD} -e "s,%%X11BASE%%,${X11BASE},g ; \
		s,%%CC%%,${CC},g ; \
		s,%%CXX%%,${CXX},g ; \
		s,%%CFLAGS%%,${CFLAGS},g ; \
		s,%%CXXFLAGS%%,${CXXFLAGS},g ; \
		s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},g ; \
		s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g ; \
		s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/setup
	@${REINPLACE_CMD} -e "s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/examples/misc/GTK/Makefile

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/*.* ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/maverik
	${INSTALL_DATA} ${WRKSRC}/incl/*.* ${PREFIX}/include/maverik
	${FIND} ${WRKSRC}/doc/MFS/man3 -name '*.3' -exec \
		${INSTALL_MAN} \{} ${MAN3PREFIX}/man/man3 \;
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/MFS/html
	${FIND} ${WRKSRC}/doc/MFS/html -name '*.html' -exec \
		${INSTALL_DATA} \{} ${DOCSDIR}/MFS/html \;
	@${MKDIR} ${DOCSDIR}/MFS/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/MFS/pdf/*.* ${DOCSDIR}/MFS/pdf
	@${MKDIR} ${DOCSDIR}/MFS/ps
	${INSTALL_DATA} ${WRKSRC}/doc/MFS/ps/*.* ${DOCSDIR}/MFS/ps
	@${MKDIR} ${DOCSDIR}/MPG/pdf
	${INSTALL_DATA} ${WRKSRC}/doc/MPG/pdf/*.* ${DOCSDIR}/MPG/pdf
	@${MKDIR} ${DOCSDIR}/MPG/ps
	${INSTALL_DATA} ${WRKSRC}/doc/MPG/ps/*.* ${DOCSDIR}/MPG/ps
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.post.mk>

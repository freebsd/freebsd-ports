# ex:ts=8
# New ports collection makefile for:	maverik
# Date created:			Nov 12, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	maverik
PORTVERSION=	6.1
CATEGORIES=	graphics
MASTER_SITES=	ftp://aig.cs.man.ac.uk/pub/Maverik/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	gtkgl.5:${PORTSDIR}/x11-toolkits/gtkglarea

USE_MESA=	yes
WANT_GTK=	yes
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

CONFIGURE_ARGS+=	--PNGLIBS="${LOCALBASE}/lib -lpng" \
			--PNGINCL="${LOCALBASE}/include"
.endif

.if defined(HAVE_GTK)
USE_GTK=	yes
CONFIGURE_ARGS+=	--GTK
.endif

post-extract:
	@${SETENV} ${SCRIPTS_ENV} ${SH} ${SCRIPTDIR}/genman3list.sh

post-patch:
	@${PERL} -pi -e "s,%%X11BASE%%,${X11BASE},g ; \
		s,%%CFLAGS%%,${CFLAGS},g ; \
		s,%%CXXFLAGS%%,${CXXFLAGS},g ; \
		s,%%PTHREAD_CFLAGS%%,${PTHREAD_CFLAGS},g ; \
		s,%%PTHREAD_LIBS%%,${PTHREAD_LIBS},g ; \
		s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/setup
	@${PERL} -pi -e "s,gtk-config,${GTK_CONFIG},g" ${WRKSRC}/examples/misc/GTK/Makefile

do-install:
	${CP} ${WRKSRC}/lib/* ${PREFIX}/lib
	@${MKDIR} ${PREFIX}/include/maverik
	${CP} ${WRKSRC}/incl/* ${PREFIX}/include/maverik
	@${CP} ${WRKSRC}/doc/MFS/man3/* ${MAN3PREFIX}/man/man3

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} -R ${WRKSRC}/doc/* ${DOCSDIR}
	@${RM} -rf ${DOCSDIR}/MFS/man3
.endif

post-clean:
	@${RM} -f ${WRKDIRPREFIX}${.CURDIR}/Makefile.inc

.if exists(${WRKDIRPREFIX}${.CURDIR}/Makefile.inc)
.include "${WRKDIRPREFIX}${.CURDIR}/Makefile.inc"
.endif

.include <bsd.port.post.mk>

# New ports collection makefile for:	nethack-gtk
# Date created:				June 15, 2000
# Whom:					Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#
BROKEN=		Gtk+-1.2.9 does not allow setuid program

PORTNAME=	nethack
PORTVERSION=	1.1.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	sf
#MASTER_SITES=	ftp://ftp.jnethack.org/pub/jnethack/
PKGNAMESUFFIX=	-gtk
DISTNAME=	${PORTNAME}-3.2.2.1
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${GTK_PATCH}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

PATCH_SITES=	ftp://ftp.jnethack.org/pub/nethack/
PATCHFILES=	nh-3.2.2-3.2.3.diff \
		nethack-gtk-1.1.5-nethack-3.2.3.patch.gz

MAINTAINER=	sf@FreeBSD.org

.include <bsd.port.pre.mk>

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS=	bdftopcf:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

USE_XPM=	yes
USE_GTK=	yes
USE_GMAKE=	yes
MAN6=		dgn_comp.6 dlb.6 lev_comp.6 nethack.6 recover.6

WRKSRC=		${WRKDIR}/${PORTNAME}-3.2.2

pre-configure:
	@ ${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@ ${ECHO} "!! You cannot install nethack and nethack-gtk in parallel !!"
	@ ${ECHO} "!! But nethack-gtk might read your prior nethack scores   !!"
	@ ${ECHO} "!! Don't forget to backup your nethack libdir if it's     !!"
	@ ${ECHO} "!! important for you                                      !!"
	@ ${ECHO} "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!"
	@ cd ${WRKSRC}/sys/unix; ${SH} setup.sh
	@ cd ${WRKSRC}; ${PATCH} -s < ${FILESDIR}/src-Makefile.diff

post-install:
	@cd ${WRKSRC}/doc; ${CHMOD} 644 *.6
	@cd ${WRKSRC}/doc; PREFIX=${PREFIX} ${MAKE} manpages
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/nethack
	${CP} ${WRKSRC}/doc/Guidebook.txt ${PREFIX}/share/doc/nethack
.endif

.include <bsd.port.post.mk>

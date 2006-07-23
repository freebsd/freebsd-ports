# New ports collection makefile for:	warsow
# Date created:		2005-11-12
# Whom:			Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
#
# $FreeBSD$
#

PORTNAME=	warsow
PORTVERSION=	0.072a
CATEGORIES=	games linux
MASTER_SITES=	http://mirrors-av.club-internet.fr/pub/games/nofrag/warsow/ \
		http://www.kpforum.net/games/
PKGNAMEPREFIX=	linux-
DISTNAME=	${PORTNAME}_0.072alpha_linux

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Free multiplayer first person shooter with cartoon design

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12 \
		${LINUXBASE}/usr/lib/libjpeg.so.62:${PORTSDIR}/graphics/linux-jpeg

ONLY_FOR_ARCHS=	i386
USE_X_PREFIX=	yes
USE_LINUX=	yes
NO_BUILD=	yes
RESTRICTED=	"Redistribution is limited, art is copyrighted"
WRKSRC=		${WRKDIR}/${PORTNAME}

WARSOWDIR=	${PREFIX}/lib/${PORTNAME}
WARSOWDIR_REL=	${WARSOWDIR:S,^${PREFIX}/,,}

SUB_FILES=	warsow-wrapper wsw_server-wrapper

PLIST=		${WRKDIR}/pkg-plist
PLIST_FILES=	bin/warsow bin/wsw_server \
		${WARSOWDIR_REL}/warsow ${WARSOWDIR_REL}/wsw_server
PORTDOCS=	*

DESKTOP_ENTRIES="Warsow" \
		"Shoot cartoon enemies" \
		"" \
		"warsow" \
		"Application;Game;" \
		false

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} != xfree86-3
.if defined(WITH_NVIDIA_GL)
RUN_DEPENDS+=	${LINUXBASE}/usr/lib/libGL.so.1:${PORTSDIR}/x11/nvidia-driver
.else
RUN_DEPENDS+=	${LINUXBASE}/usr/X11R6/lib/libGL.so.1:${PORTSDIR}/graphics/linux_dri
.endif
.else
RUN_DEPENDS+=	${LINUXBASE}/lib/libGL.so.1:${PORTSDIR}/graphics/linux_glx
.endif

post-patch:
	@${FIND} ${WRKSRC}/basewsw -type d -empty -exec ${TOUCH} "{}/.keep_me" \;

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}/basewsw && \
	${FIND} * -type f | ${SORT} \
		| ${SED} -e 's|^|${WARSOWDIR_REL}/basewsw/|' >> ${PLIST} && \
	${FIND} * -type d | ${SORT} -r \
		| ${SED} -e 's|^|@dirrm ${WARSOWDIR_REL}/basewsw/|' >> ${PLIST}

do-install:
	cd ${WRKSRC}/basewsw && \
	${FIND} * -type d -exec ${MKDIR} "${WARSOWDIR}/basewsw/{}" \; && \
	${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${WARSOWDIR}/basewsw/{}" \;
.for f in warsow wsw_server
	${INSTALL_PROGRAM} ${WRKSRC}/${f} ${WARSOWDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${f}-wrapper ${PREFIX}/bin/${f}
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.  for f in Shader* bots_navigation.txt changelog.txt contact.txt demoavi.txt \
	entities.def linux_sound_sdl.txt quick* server_admin.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.  endfor
.endif

	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

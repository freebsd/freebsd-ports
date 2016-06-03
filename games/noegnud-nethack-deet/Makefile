# Created by: Leland Wang <llwang@infor.org>
# $FreeBSD$

PORTNAME=	noegnud
PORTVERSION=	0.8.3
PORTREVISION=	12
CATEGORIES=	games
MASTER_SITES=	http://www.darkarts.co.za/projects/noegnud/downloads/${PORTVERSION}/:noegnud	\
		SF/nethack/nethack/3.4.2:nethack
PKGNAMESUFFIX=	-nethack-deet
DISTFILES=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}:noegnud	\
		nethack-342.tgz:nethack
EXTRACT_ONLY=	${DISTNAME}_linux_src-minimal${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The noeGNUd UI for Nethack with DeeT's hack font patch

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

RUN_DEPENDS=	noegnud-data>0:games/noegnud-data

NOEGNUDVERSION=	${PORTNAME}-0.8.0
USES=		bison tar:bzip2
USE_GL=		yes
USE_SDL=	sdl image mixer
WRKSRC=		${WRKDIR}/${DISTNAME}/variants
PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}
ALL_TARGET=	nh342-dt
INSTALL_TARGET=	install_nh342-dt
MAKE_JOBS_UNSAFE=	yes

pre-everything::
	@${ECHO_MSG} "This port depends on SDL with OpenGL support."
	@${ECHO_MSG} "If your SDL does not support OpenGL, hit ^C now and reinstall SDL"
	@${ECHO_MSG} "with OpenGL support turned on."

post-extract:
	@${CP} ${DISTDIR}/nethack-342.tgz ${WRKSRC}/tarballs
	(cd ${WRKSRC} && ${MAKE} nethack-3.4.2-deet)

post-patch:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.2-deet)
	@(${PATCH} ${PATCH_ARGS} < ${FILESDIR}/noegnud-nethack-deet.patch)
	@${REINPLACE_CMD} 's|%%PREFIX%%|${PREFIX}|' ${WRKSRC}/Makefile
	@${REINPLACE_CMD} -E -e 's,ch(grp|own),true,' \
		-e '/(^VARDIR|ln -s|sed)/! s,(GAME|SHELL|VAR)DIR),DESTDIR)$$(&,g' \
		-e '/ln -s/ s,SHELLDIR,DESTDIR)$$(&,2' \
		${WRKSRC}/${NOEGNUDVERSION}-nethack-3.4.2-deet/sys/unix/Makefile.top

do-configure:
	(cd ${WRKSRC} && ${MAKE} ${NOEGNUDVERSION}-nethack-3.4.2-deet/Makefile)

.include <bsd.port.mk>

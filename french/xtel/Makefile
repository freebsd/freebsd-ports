# Ports collection makefile for:  xtel
# Date created:			  Wed Jul 11, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	xtel
PORTVERSION=	3.3.0
PORTREVISION=	1
CATEGORIES=	french comms emulators
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

MAINTAINER=	thierry@pompo.net

LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg

# Remark: Xtel can serve a network, and emulate TVR and I-Minitel, but this is
# the first release of this port, and these functionnalities have not (yet)
# been implemented.

USE_IMAKE=	yes
USE_XPM=	yes

MAN1=	xtel.1 xteld.1

.include <bsd.port.pre.mk>

.if defined(LANG)
LANGUE!=${ECHO} ${LANG} | ${CUT} -c 1-2
.else
LANGUE=	english
.endif

DOCS=	COPYING COPYRIGHT FAQ.txt HISTOIRE.txt LISEZMOI.txt README_IMINITEL.txt
PATCH_FILES=	Imakefile

post-patch:
.for FILE in ${PATCH_FILES}
	@${PERL} -pi -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/${FILE}
.endfor
	find ${WRKSRC} -type f | xargs ${PERL} -pi -e \
		"s@#include.*<malloc.h>@#include <stdlib.h>@g"

pre-configure:
.if !exists(${PREFIX}/lib/X11/config/host.def)
	${CP} ${FILESDIR}/host.def ${PREFIX}/lib/X11/config
HOST_DEF_INSTALLED_BY_XTEL=	yes
.endif

post-configure:
.if defined(HOST_DEF_INSTALLED_BY_XTEL)
	${RM} ${PREFIX}/lib/X11/config/host.def
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for FILE in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${DOCSDIR}
.endfor
	@${ECHO}
	@(if [ 0${LANGUE} = 0fr ] ; then \
	  ${ECHO_MSG} "La documentation a été installée dans ${DOCSDIR}." ; \
	else \
	  ${ECHO_MSG} "Documentation installed in ${DOCSDIR}." ; \
	fi)
.endif
	@${TOUCH} ${PREFIX}/lib/X11/xtel/xtel.log
	@(if [ 0${LANGUE} = 0fr ] ; then \
		${CP} ${PKGMESSAGE}-fr ${WRKDIR}/pkg-message ; \
	else \
		${CP} ${PKGMESSAGE} ${WRKDIR} ; \
	fi)
	@${ECHO}
	@${CAT} ${WRKDIR}/pkg-message | ${SED} -e "s:%%PREFIX%%:${PREFIX}:g"
	@${ECHO}

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

.include <bsd.port.post.mk>

# Ports collection makefile for:  xtel
# Date created:			  Wed Jul 11, 2001
# Whom:				  Thierry Thomas (<thierry@thomas.as>)
#
# $FreeBSD$
#

PORTNAME=	xtel
PORTVERSION=	3.3.0
PORTREVISION=	2
CATEGORIES=	french comms emulators
MASTER_SITES=	http://pficheux.free.fr/xtel/download/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	An emulator for the french Minitel

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

# Remark: Xtel can serve a network, and emulate TVR and I-Minitel, but this is
# the first release of this port, and these functionnalities have not (yet)
# been implemented.

USE_IMAKE=	yes
USE_XPM=	yes
USE_REINPLACE=	yes

MAN1=	xtel.1 xteld.1

PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if defined(LANG)
LANGUE!=${ECHO_CMD} ${LANG} | ${CUT} -c 1-2
.else
LANGUE=	english
.endif

DOCS=	COPYING COPYRIGHT FAQ.txt HISTOIRE.txt LISEZMOI.txt README_IMINITEL.txt
PATCH_FILES=	Imakefile

post-patch:
.for FILE in ${PATCH_FILES}
	${CHMOD} u+w ${WRKSRC}/${FILE}
	${REINPLACE_CMD} -e "s:%%LOCALBASE%%:${LOCALBASE}:g" ${WRKSRC}/${FILE}
.endfor

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
	  ${ECHO_MSG} "===> La documentation a été installée dans ${DOCSDIR}." ; \
	else \
	  ${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}." ; \
	fi)
.endif
	@${TOUCH} ${PREFIX}/lib/X11/xtel/xtel.log
	@(if [ 0${LANGUE} = 0fr ] ; then \
		${CP} ${FILESDIR}/pkg-message-fr.in ${PKGMESSAGE} ; \
	else \
		${CP} ${FILESDIR}/pkg-message.in ${PKGMESSAGE} ; \
	fi)
	@${ECHO}
	@${SED} -e "s:%%PREFIX%%:${PREFIX}:g" ${PKGMESSAGE}
	@${ECHO}

.include <bsd.port.post.mk>

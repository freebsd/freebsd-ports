# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.4.7
PORTCOMMENT=	The Automated Program Generator
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	guile.10:${PORTSDIR}/lang/guile \
		xml2.5:${PORTSDIR}/textproc/libxml2

USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libguile=${LOCALBASE} --with-libxml2=${LOCALBASE}
INSTALLS_SHLIB=	yes

MAN1=	autogen.1 autoopts-config.1 columns.1 getdefs.1 xml2ag.1
MAN3=	optionFree.3 optionLoadLine.3 optionProcess.3 optionRestore.3 \
	optionSaveFile.3 optionSaveState.3 optionVersion.3

pre-build:
	@cd ${WRKSRC}/snprintfv && ${SETENV} ${MAKE_ENV} \
		${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

.include <bsd.port.mk>

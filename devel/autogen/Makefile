# ex:ts=8
# New ports collection makefile for:	autogen
# Date created:		Mar 11, 2001
# Whom:			Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	autogen
PORTVERSION=	5.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		${MASTER_SITE_GNU:S/$/:gnu/}
MASTER_SITE_SUBDIR=	${PORTNAME} ${PORTNAME}/rel${PORTVERSION}/:gnu
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:DEFAULT,gnu

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Automated Program Generator

LIB_DEPENDS=	guile.15:${PORTSDIR}/lang/guile

USE_GNOME=	gnometarget libxml2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libguile=yes --with-libxml2=yes
INSTALLS_SHLIB=	yes

MAN1=	autogen.1 autoopts-config.1 columns.1 getdefs.1 xml2ag.1
MAN3=	optionFree.3 optionLoadLine.3 optionProcess.3 optionRestore.3 \
	optionSaveFile.3 optionSaveState.3 optionVersion.3
INFO=	autogen

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Build fails on amd64"
.endif

.include <bsd.port.post.mk>

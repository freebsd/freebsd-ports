# New ports collection makefile for:    gnat-glade
# Date created:         3 May 2000
# Whom:                 sam@inf.enst.fr
#
# $FreeBSD$
#

PORTNAME=	gnat-glade
PORTVERSION=	2005
PORTREVISION=	1
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTNAME=	glade-gpl-${PORTVERSION}-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	mek@mek.uz.ua
COMMENT=	GNU Ada distributed systems annex

BUILD_DEPENDS=	gnatgcc:${PORTSDIR}/lang/gnat

BROKEN=		does not build

USE_AUTOTOOLS=	automake:14 autoconf:262
USE_GMAKE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --program-transform-name=''

.include <bsd.port.pre.mk>

# Check for GLADE sources.
GLADE_SRC=${DISTNAME}${EXTRACT_SUFX}

.if !exists(${DISTDIR}/${GLADE_SRC}) && !defined(PACKAGE_BUILDING)
ECHO_MSG=/usr/bin/printf
IGNORE=: Because of licensing and registration restrictions,\n\
you must fetch the source distribution manually.\n\
Please access http://libre.adacore.com/\n\
with a web browser, register (it's free), and log in.  Download the source\n\
file:\n\
\t${DISTFILES}\n\
and place it in ${DISTDIR}.\n
.endif

.include <bsd.port.post.mk>

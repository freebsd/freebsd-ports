# New ports collection makefile for:	gtkmozedit
# Date created:		2005-10-12
# Whom:			Michael Johnson <ahze@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkmozedit
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	devel editors www
MASTER_SITES=	${MASTER_SITE_GNOME}
MASTER_SITE_SUBDIR=	sources/${PORTNAME}/${PORTVERSION:R}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Text editor widget based on Mozilla's editing functionality

BUILD_DEPENDS=	${X11BASE}/libdata/pkgconfig/${MOZILLA}-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/${MOZILLA}${HEADERS_SUFX}
RUN_DEPENDS=	${X11BASE}/libdata/pkgconfig/${MOZILLA}-plugin${HEADERS_SUFX}.pc:${PORTSDIR}/www/${MOZILLA}${HEADERS_SUFX}

USE_BZIP2=	yes
USE_REINPLACE=	yes
WITH_MOZILLA?=	firefox
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15
USE_GNOME=	gnomehack

.include <bsd.port.pre.mk>

.if !defined(WITH_MOZILLA)
MOZILLA=	firefox
HEADERS_SUFX=
.elif ${WITH_MOZILLA}=="mozilla"
MOZILLA=	mozilla
HEADERS_SUFX=
.else
MOZILLA=	firefox
HEADERS_SUFX=
.endif

.if ${WITH_MOZILLA}=="firefox"
CONFIGURE_ARGS+=	--with-firefox
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} " By default the port uses www/firefox for gecko support, but you can"
	@${ECHO_MSG} " change this by defining WITH_MOZILLA to one of the following values:"
	@${ECHO_MSG}
	@${ECHO_MSG} "  mozilla       "
#	@${ECHO_MSG} "  mozilla-devel "
	@${ECHO_MSG} ""

post-patch:
	@${REINPLACE_CMD} -e 's|firefox-nspr|firefox-xpcom|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>

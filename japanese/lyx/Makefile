# New ports collection makefile for:	lyx
# Date created:		27 April 1999
# Whom:			Seiichirou Hiraoka
#
# $FreeBSD$
#

PORTNAME=	lyx
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	japanese print
MASTER_SITES=	ftp://ftp.lyx.org/pub/lyx/stable/ \
		ftp://ftp.sdsc.edu/pub/other/lyx/stable/ \
		${MASTER_SITE_LOCAL:S/$/:local/}
MASTER_SITE_SUBDIR=	flathill/:local
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME}-jp-kit0.10b4for${PORTVERSION}.tar.gz:local

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Document processor interfaced with LaTeX (nearly WYSIWYG)

LIB_DEPENDS=	forms.1:${PORTSDIR}/x11-toolkits/xforms

USE_XPM=	yes
USE_PERL5=	yes
GNU_CONFIGURE=	yes
STRIP=
CONFIGURE_ARGS=	--with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"
MAN1=		lyx.1 reLyX.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		Does not compile with GCC 4.2
.endif

pre-fetch:
.if !defined(WITH_ISPELL)
	@${ECHO_MSG} "if you want this port build with spell checker type"
	@${ECHO_MSG} "make WITH_ISPELL=yes"
.endif

post-patch:
	@cd ${WRKSRC}; ${PATCH} -p1 < ../lyx-jp-patch

post-install:
	${STRIP_CMD} ${PREFIX}/bin/lyx
	${INSTALL_DATA} ${WRKDIR}/ChangeLog.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKDIR}/README.jis ${PREFIX}/share/lyx
	${INSTALL_DATA} ${WRKSRC}/lib/lyxrc.jp ${PREFIX}/share/lyx

.include <bsd.port.post.mk>
